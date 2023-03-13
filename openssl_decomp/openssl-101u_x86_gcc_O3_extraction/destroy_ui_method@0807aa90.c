
void destroy_ui_method(void)

{
  if (ui_method != (UI_METHOD *)0x0) {
    UI_destroy_method(ui_method);
    ui_method = (UI_METHOD *)0x0;
  }
  return;
}

