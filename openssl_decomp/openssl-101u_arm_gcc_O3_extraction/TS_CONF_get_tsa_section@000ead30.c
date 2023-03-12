
char * TS_CONF_get_tsa_section(CONF *param_1,char *param_2)

{
  if ((param_2 == (char *)0x0) &&
     (param_2 = NCONF_get_string(param_1,"tsa","default_tsa"), param_2 == (char *)0x0)) {
    __fprintf_chk(stderr,1,"variable lookup failed for %s::%s\n","tsa","default_tsa");
  }
  return param_2;
}

