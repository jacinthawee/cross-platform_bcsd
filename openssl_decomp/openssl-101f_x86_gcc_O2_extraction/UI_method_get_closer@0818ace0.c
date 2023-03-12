
int UI_method_get_closer(UI *param_1)

{
  if (param_1 != (UI *)0x0) {
    return *(int *)(param_1 + 0x14);
  }
  return 0;
}

