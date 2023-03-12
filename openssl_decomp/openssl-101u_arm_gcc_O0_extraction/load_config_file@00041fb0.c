
CONF * load_config_file(CONF *param_1)

{
  CONF *conf;
  int iVar1;
  char *filename;
  BIO *in;
  int local_1c [2];
  
  local_1c[0] = -1;
  if (((param_1 != (CONF *)0x0) ||
      (param_1 = (CONF *)getenv("OPENSSL_CONF"), param_1 != (CONF *)0x0)) ||
     (param_1 = (CONF *)getenv("SSLEAY_CONF"), param_1 != (CONF *)0x0)) {
    conf = NCONF_new((CONF_METHOD *)0x0);
    if ((conf == (CONF *)0x0) || (iVar1 = NCONF_load(conf,(char *)param_1,local_1c), iVar1 < 1)) {
      if (local_1c[0] < 1) {
        BIO_printf(bio_err,"error loading the config file \'%s\'\n",param_1);
      }
      else {
        BIO_printf(bio_err,"error on line %ld of config file \'%s\'\n",local_1c[0],param_1);
      }
      if (conf == (CONF *)0x0) {
        return (CONF *)0x0;
      }
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
    param_1 = conf;
    if (iVar1 == 0) {
      ERR_print_errors(bio_err);
    }
  }
  return param_1;
}

