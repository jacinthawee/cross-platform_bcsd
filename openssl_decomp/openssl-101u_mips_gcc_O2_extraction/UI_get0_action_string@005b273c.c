
char * UI_get0_action_string(UI_STRING *uis)

{
  if ((uis != (UI_STRING *)0x0) && ((*(int *)uis == 1 || (*(int *)uis == 3)))) {
    return *(char **)(uis + 0x10);
  }
  return (char *)0x0;
}

