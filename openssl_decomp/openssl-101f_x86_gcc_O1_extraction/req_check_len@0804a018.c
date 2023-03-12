
undefined4 __regparm3 req_check_len(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((param_2 < 1) || (param_2 <= param_1)) {
    if ((param_3 < 0) || (param_1 <= param_3)) {
      uVar1 = 1;
    }
    else {
      BIO_printf(bio_err,"string is too long, it needs to be less than  %d bytes long\n",param_3,
                 param_1);
      uVar1 = 0;
    }
  }
  else {
    BIO_printf(bio_err,"string is too short, it needs to be at least %d bytes long\n",param_2,
               param_3);
    uVar1 = 0;
  }
  return uVar1;
}

