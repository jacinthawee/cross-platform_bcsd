
void destroy_ui_method(void)

{
  if (ui_method != 0) {
    (*(code *)PTR_UI_destroy_method_006a8c5c)();
    ui_method = 0;
  }
  return;
}

