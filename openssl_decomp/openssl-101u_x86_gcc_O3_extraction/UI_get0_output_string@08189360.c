
char * UI_get0_output_string(UI_STRING *uis)

{
  if (uis != (UI_STRING *)0x0) {
    return *(char **)(uis + 4);
  }
  return (char *)0x0;
}

