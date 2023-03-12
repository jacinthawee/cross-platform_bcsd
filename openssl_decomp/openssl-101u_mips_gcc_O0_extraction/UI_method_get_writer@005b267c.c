
int UI_method_get_writer(UI *param_1,UI_STRING *param_2)

{
  if (param_1 != (UI *)0x0) {
    return *(int *)(param_1 + 8);
  }
  return 0;
}

