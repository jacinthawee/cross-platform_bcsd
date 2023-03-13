
char * UI_get0_test_string(UI_STRING *uis)

{
  if ((uis != (UI_STRING *)0x0) && (*(int *)uis == 2)) {
    return *(char **)(uis + 0x18);
  }
  return (char *)0x0;
}

