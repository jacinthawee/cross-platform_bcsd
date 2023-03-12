
EVP_MD * TS_CONF_set_digests(CONF *param_1,char *param_2,undefined4 param_3)

{
  EVP_MD *line;
  EVP_MD *st;
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  line = (EVP_MD *)NCONF_get_string(param_1,param_2,"digests");
  if (line == (EVP_MD *)0x0) {
    __fprintf_chk(stderr,1,"variable lookup failed for %s::%s\n",param_2,"digests");
    st = line;
  }
  else {
    st = (EVP_MD *)X509V3_parse_list((char *)line);
    if (st == (EVP_MD *)0x0) {
      __fprintf_chk(stderr,1,"invalid variable value for %s::%s\n",param_2,"digests");
      line = st;
    }
    else {
      line = (EVP_MD *)sk_num((_STACK *)st);
      iVar3 = 0;
      if (line == (EVP_MD *)0x0) {
        __fprintf_chk(stderr,1,"invalid variable value for %s::%s\n",param_2,"digests");
      }
      else {
        do {
          iVar1 = sk_num((_STACK *)st);
          if (iVar1 <= iVar3) {
            line = (EVP_MD *)0x1;
            break;
          }
          pvVar2 = sk_value((_STACK *)st,iVar3);
          if (*(char **)((int)pvVar2 + 8) == (char *)0x0) {
            line = EVP_get_digestbyname(*(char **)((int)pvVar2 + 4));
          }
          else {
            line = EVP_get_digestbyname(*(char **)((int)pvVar2 + 8));
          }
          if (line == (EVP_MD *)0x0) {
            __fprintf_chk(stderr,1,"invalid variable value for %s::%s\n",param_2,"digests");
            break;
          }
          line = (EVP_MD *)TS_RESP_CTX_add_md(param_3,line);
          iVar3 = iVar3 + 1;
        } while (line != (EVP_MD *)0x0);
      }
    }
  }
  sk_pop_free((_STACK *)st,X509V3_conf_free + 1);
  return line;
}

