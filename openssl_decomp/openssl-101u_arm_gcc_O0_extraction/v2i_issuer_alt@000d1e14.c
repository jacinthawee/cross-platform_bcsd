
_STACK * v2i_issuer_alt(X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,_STACK *param_3)

{
  _STACK *st;
  GENERAL_NAME *data;
  int iVar1;
  void *pvVar2;
  X509_EXTENSION *ext;
  _STACK *p_Var3;
  int iVar4;
  int iVar5;
  char *name;
  char *__s1;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x22,0x99,0x41,"v3_alt.c",0xf7);
  }
  else {
    iVar5 = 0;
    while( true ) {
      iVar1 = sk_num(param_3);
      if (iVar1 <= iVar5) {
        return st;
      }
      pvVar2 = sk_value(param_3,iVar5);
      iVar1 = name_cmp(*(char **)((int)pvVar2 + 4),"issuer");
      __s1 = *(char **)((int)pvVar2 + 8);
      if (iVar1 != 0) break;
      if (__s1 == (char *)0x0) {
LAB_000d1eba:
        ERR_put_error(0x22,0x75,0x7c,"v3_alt.c",0x213);
        goto LAB_000d1fc0;
      }
      iVar1 = strcmp(__s1,"copy");
      if (iVar1 != 0) {
        name = *(char **)((int)pvVar2 + 4);
        goto LAB_000d1e9e;
      }
      if (param_2 == (X509V3_CTX *)0x0) {
LAB_000d1fa8:
        ERR_put_error(0x22,0x7b,0x7f,"v3_alt.c",0x118);
        goto LAB_000d1fc0;
      }
      if (param_2->flags != 1) {
        if (param_2->issuer_cert == (X509 *)0x0) goto LAB_000d1fa8;
        iVar1 = X509_get_ext_by_NID(param_2->issuer_cert,0x55,-1);
        if (-1 < iVar1) {
          ext = X509_get_ext(param_2->issuer_cert,iVar1);
          if ((ext == (X509_EXTENSION *)0x0) ||
             (p_Var3 = (_STACK *)X509V3_EXT_d2i(ext), p_Var3 == (_STACK *)0x0)) {
            ERR_put_error(0x22,0x7b,0x7e,"v3_alt.c",0x120);
            goto LAB_000d1fc0;
          }
          iVar1 = 0;
          while( true ) {
            iVar4 = sk_num(p_Var3);
            if (iVar4 <= iVar1) break;
            pvVar2 = sk_value(p_Var3,iVar1);
            iVar4 = sk_push(st,pvVar2);
            iVar1 = iVar1 + 1;
            if (iVar4 == 0) {
              ERR_put_error(0x22,0x7b,0x41,"v3_alt.c",0x127);
              goto LAB_000d1fc0;
            }
          }
          sk_free(p_Var3);
        }
      }
LAB_000d1e60:
      iVar5 = iVar5 + 1;
    }
    name = *(char **)((int)pvVar2 + 4);
    if (__s1 == (char *)0x0) goto LAB_000d1eba;
LAB_000d1e9e:
    iVar1 = name_cmp(name,"email");
    if (iVar1 == 0) {
      iVar4 = 1;
    }
    else {
      iVar1 = name_cmp(name,"URI");
      iVar4 = 6;
      if (iVar1 != 0) {
        iVar1 = name_cmp(name,"DNS");
        iVar4 = 2;
        if (iVar1 != 0) {
          iVar1 = name_cmp(name,"RID");
          iVar4 = 8;
          if (iVar1 != 0) {
            iVar1 = name_cmp(name,"IP");
            iVar4 = 7;
            if (iVar1 != 0) {
              iVar1 = name_cmp(name,"dirName");
              iVar4 = 4;
              if ((iVar1 != 0) && (iVar4 = name_cmp(name,"otherName"), iVar4 != 0)) {
                ERR_put_error(0x22,0x75,0x75,"v3_alt.c",0x226);
                ERR_add_error_data(2,"name=",name);
                goto LAB_000d1fc0;
              }
            }
          }
        }
      }
    }
    data = a2i_GENERAL_NAME((GENERAL_NAME *)0x0,param_1,param_2,iVar4,__s1,0);
    if (data != (GENERAL_NAME *)0x0) {
      sk_push(st,data);
      goto LAB_000d1e60;
    }
LAB_000d1fc0:
    sk_pop_free(st,GENERAL_NAME_free + 1);
    st = (_STACK *)0x0;
  }
  return st;
}

