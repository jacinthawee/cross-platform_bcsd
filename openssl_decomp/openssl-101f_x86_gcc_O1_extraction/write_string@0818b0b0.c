
undefined4 write_string(undefined4 param_1,UI_STRING *param_2)

{
  FILE *__stream;
  UI_string_types UVar1;
  char *__s;
  
  UVar1 = UI_get_string_type(param_2);
  __stream = tty_out;
  if (UVar1 + ~UIT_BOOLEAN < 2) {
    __s = UI_get0_output_string(param_2);
    fputs(__s,__stream);
    fflush(tty_out);
  }
  return 1;
}

