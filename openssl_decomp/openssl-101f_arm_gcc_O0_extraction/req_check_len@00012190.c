
undefined4 req_check_len(int param_1,int param_2,int param_3,undefined4 param_4)

{
  if ((param_1 < param_2) && (0 < param_2)) {
    BIO_printf(bio_err,"string is too short, it needs to be at least %d bytes long\n",param_2,
               param_2,param_4);
    return 0;
  }
  if ((param_3 < param_1) && (-1 < param_3)) {
    BIO_printf(bio_err,"string is too long, it needs to be less than  %d bytes long\n",param_3,
               &bio_err,param_4);
    return 0;
  }
  return 1;
}

