
undefined4 write_string(undefined4 param_1,UI_STRING *param_2)

{
  UI_string_types UVar1;
  char *pcVar2;
  
  UVar1 = UI_get_string_type(param_2);
  if (UVar1 + ~UIT_BOOLEAN < 2) {
    pcVar2 = UI_get0_output_string(param_2);
    (*(code *)PTR_fputs_006a9954)(pcVar2,tty_out);
    (*(code *)PTR_fflush_006a9b04)(tty_out);
  }
  return 1;
}

