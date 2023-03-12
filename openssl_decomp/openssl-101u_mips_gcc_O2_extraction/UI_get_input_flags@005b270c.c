
int UI_get_input_flags(UI_STRING *uis)

{
  if (uis != (UI_STRING *)0x0) {
    return *(int *)(uis + 8);
  }
  return 0;
}

