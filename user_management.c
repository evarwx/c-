# include<stdio.h>
# include<string.h>
# include<unistd.h>
# include<conio.h>


#define MAX_USERS 10
#define CREDENTIAL_LENGTH 50

void register_user();
int login_user(); // returns the user index

typedef struct{
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];
}user;

user users[MAX_USERS];
int user_count =0;


int main(){
    int option;
   
   while(1){
    printf("\n welcome to the user management ");
    printf("\n1. register ");
    printf("\n.2 login");
    printf("\n3. exit")
    printf("\nSelect an option: ");
    scanf("%d",&option);
    getchar();
    
    switch(option)
    {

    case 1:
     register_user();


    break;

    case 2:
      int user_index = login_user();
      if (user_index >= 0){
        printf("\nLogin successful! welcome %s !",users[user_index].username)
      }else{
        printf("\nlogin failed plese check your password or username \n");
 }
    break;

    case 3:
    printf("Exiting the program.\n")
    return 0;
    break;

    default:
    printf("\nInvalid option selected. plese try again.\n")
    break;

}

   }
   return 0;
}

void register_user(){
     if (user_count == MAX_USERS) {
    printf("\nMaxximum %d users are supported! No more registrations Allowed!!!!\n", MAX_USERS);
    return;
  }

  int new_index = user_count;
  printf("\nRegister a new user");
  input_credentials(users[new_index].username, users[new_index].password);
  user_count++;
  printf("\nRegistration successful!\n");

}

int login_user() {
  char username[CREDENTIAL_LENGTH];
  char password[CREDENTIAL_LENGTH];

  input_credentials(username, password);

  for (int i = 0; i < user_count; i++) {
    if (strcmp(username, users[i].username) == 0 && 
        strcmp(password, users[i].password) == 0) {
      return i;
    }
  }

  return -1;
}

void input_credentials(char* username, char* password) {
  printf("\nEnter username: ");
  fgets(username, CREDENTIAL_LENGTH, stdin);
  fix_fgets_input(username);
  printf("Enter password (masking enabled): ");
  fflush(stdout);

    // Change terminal Properties
  struct termios old_props, new_props;
  tcgetattr(STDIN_FILENO, &old_props);
  new_props = old_props;
  new_props.c_lflag = ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSANOW, &new_props);

  char ch;
  int i = 0;
  while ((ch = getchar()) != '\n' && ch != EOF) {
    // 127 is ASCII for DEL
    if (ch == '\b' || ch == 127) {
      if (i > 0) {
        i--;
        printf("\b \b");
      }
    } else {
      password[i++] = ch;
      printf("*");
    }
  }
  password[i] = '\0';
  tcsetattr(STDIN_FILENO, TCSANOW, &old_props);
}

void fix_fgets_input(char* string) {
  int index = strcspn(string, "\n");
  string[index] = '\0';
}