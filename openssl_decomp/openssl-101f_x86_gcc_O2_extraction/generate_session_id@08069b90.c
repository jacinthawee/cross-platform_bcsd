
undefined4 generate_session_id(SSL *param_1,uchar *param_2,uint *param_3)

{
  char *__src;
  uint __n;
  int iVar1;
  int iVar2;
  
  iVar2 = 10;
  while( true ) {
    RAND_pseudo_bytes(param_2,*param_3);
    __src = session_id_prefix;
    __n = strlen(session_id_prefix);
    if (*param_3 < __n || *param_3 == __n) {
      __n = *param_3;
    }
    memcpy(param_2,__src,__n);
    iVar1 = SSL_has_matching_session_id(param_1,param_2,*param_3);
    if (iVar1 == 0) break;
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) {
      return 0;
    }
  }
  return 1;
}

