
int UI_method_get_reader(UI *param_1,UI_STRING *param_2)

{
  if (param_1 != (UI *)0x0) {
    return *(int *)(param_1 + 0x10);
  }
  return 0;
}

