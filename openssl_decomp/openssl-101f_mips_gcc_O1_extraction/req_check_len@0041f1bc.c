
undefined4 req_check_len(int param_1,int param_2,int param_3,undefined4 param_4)

{
  char *pcVar1;
  
  if ((param_2 < 1) || (param_2 <= param_1)) {
    if ((param_3 < 0) || (param_1 <= param_3)) {
      return 1;
    }
    pcVar1 = "string is too long, it needs to be less than  %d bytes long\n";
  }
  else {
    pcVar1 = "string is too short, it needs to be at least %d bytes long\n";
    param_3 = param_2;
  }
  (*(code *)PTR_BIO_printf_006a7f38)
            (*(undefined4 *)PTR_bio_err_006a7f3c,pcVar1,param_3,param_4,&_gp);
  return 0;
}

