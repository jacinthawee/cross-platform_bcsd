
int bio_dump_callback(BIO *param_1,int param_2,char *param_3,undefined4 param_4,undefined4 param_5,
                     int param_6)

{
  BIO *bio;
  char *format;
  
  bio = (BIO *)BIO_get_callback_arg(param_1);
  if (bio == (BIO *)0x0) {
    return param_6;
  }
  if (param_2 == 0x82) {
    format = "read from %p [%p] (%lu bytes => %ld (0x%lX))\n";
  }
  else {
    if (param_2 != 0x83) {
      return param_6;
    }
    format = "write to %p [%p] (%lu bytes => %ld (0x%lX))\n";
  }
  BIO_printf(bio,format,param_1,param_3,param_4,param_6,param_6);
  BIO_dump(bio,param_3,param_6);
  return param_6;
}

