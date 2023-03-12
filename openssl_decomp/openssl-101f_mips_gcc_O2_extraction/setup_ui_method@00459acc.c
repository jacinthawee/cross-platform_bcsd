
undefined4 setup_ui_method(void)

{
  ui_method = (*(code *)PTR_UI_create_method_006a8c48)("OpenSSL application user interface");
  (*(code *)PTR_UI_method_set_opener_006a8c4c)(ui_method,ui_open);
  (*(code *)PTR_UI_method_set_reader_006a8c50)(ui_method,ui_read);
  (*(code *)PTR_UI_method_set_writer_006a8c54)(ui_method,ui_write);
  (*(code *)PTR_UI_method_set_closer_006a8c58)(ui_method,ui_close);
  return 0;
}

