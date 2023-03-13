
CONF * __regparm3 load_config_file(char *param_1)

{
  CONF *conf;
  int iVar1;
  char *filename;
  BIO *in;
  int in_GS_OFFSET;
  int local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = -1;
  if (param_1 == (char *)0x0) {
    param_1 = getenv("OPENSSL_CONF");
    if (param_1 == (char *)0x0) {
      param_1 = getenv("SSLEAY_CONF");
      if (param_1 == (char *)0x0) {
        conf = (CONF *)0x0;
        goto LAB_08091588;
      }
    }
  }
  conf = NCONF_new((CONF_METHOD *)0x0);
  if (conf == (CONF *)0x0) {
LAB_080915c0:
    if (local_14 < 1) {
      BIO_printf(bio_err,"error loading the config file \'%s\'\n",param_1);
    }
    else {
      BIO_printf(bio_err,"error on line %ld of config file \'%s\'\n",local_14,param_1);
    }
    if (conf == (CONF *)0x0) {
      conf = (CONF *)0x0;
      goto LAB_08091588;
    }
  }
  else {
    iVar1 = NCONF_load(conf,param_1,&local_14);
    if (iVar1 < 1) goto LAB_080915c0;
  }
  BIO_printf(bio_err,"Using configuration from %s\n",param_1);
  filename = NCONF_get_string(conf,(char *)0x0,"oid_file");
  if (filename == (char *)0x0) {
    ERR_clear_error();
  }
  else {
    in = BIO_new_file(filename,"r");
    if (in == (BIO *)0x0) {
      ERR_print_errors(bio_err);
    }
    else {
      OBJ_create_objects(in);
      BIO_free_all(in);
    }
  }
  iVar1 = add_oid_section(bio_err,conf);
  if (iVar1 == 0) {
    ERR_print_errors(bio_err);
  }
LAB_08091588:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return conf;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

