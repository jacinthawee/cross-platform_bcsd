
undefined4 setup_ui_method(void)

{
  ui_method = UI_create_method("OpenSSL application user interface");
  UI_method_set_opener(ui_method,ui_open);
  UI_method_set_reader(ui_method,ui_read);
  UI_method_set_writer(ui_method,ui_write);
  UI_method_set_closer(ui_method,ui_close);
  return 0;
}

