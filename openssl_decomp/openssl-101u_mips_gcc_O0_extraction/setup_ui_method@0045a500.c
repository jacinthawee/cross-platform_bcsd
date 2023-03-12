
undefined4 setup_ui_method(void)

{
  ui_method = (*(code *)PTR_UI_create_method_006a7b5c)("OpenSSL application user interface");
  (*(code *)PTR_UI_method_set_opener_006a7b60)(ui_method,ui_open);
  (*(code *)PTR_UI_method_set_reader_006a7b64)(ui_method,ui_read);
  (*(code *)PTR_UI_method_set_writer_006a7b68)(ui_method,ui_write);
  (*(code *)PTR_UI_method_set_closer_006a7b6c)(ui_method,ui_close);
  return 0;
}

