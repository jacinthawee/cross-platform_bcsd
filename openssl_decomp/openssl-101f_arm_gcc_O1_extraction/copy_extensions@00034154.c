
int copy_extensions(X509 *param_1,X509_REQ *param_2,int param_3)

{
  _STACK *st;
  int iVar1;
  X509_EXTENSION *ex;
  ASN1_OBJECT *obj;
  X509_EXTENSION *a;
  int iVar2;
  
  if ((param_2 == (X509_REQ *)0x0 || param_1 == (X509 *)0x0) || (iVar2 = 0, param_3 == 0)) {
    return 1;
  }
  st = (_STACK *)X509_REQ_get_extensions(param_2);
  iVar1 = sk_num(st);
  if (0 < iVar1) {
    do {
      ex = (X509_EXTENSION *)sk_value(st,iVar2);
      obj = X509_EXTENSION_get_object(ex);
      iVar1 = X509_get_ext_by_OBJ(param_1,obj,-1);
      if (iVar1 == -1) {
LAB_000341da:
        iVar1 = X509_add_ext(param_1,ex,-1);
        if (iVar1 == 0) goto LAB_000341f8;
      }
      else if (param_3 != 1) {
        do {
          a = X509_get_ext(param_1,iVar1);
          X509_delete_ext(param_1,iVar1);
          X509_EXTENSION_free(a);
          iVar1 = X509_get_ext_by_OBJ(param_1,obj,-1);
        } while (iVar1 != -1);
        goto LAB_000341da;
      }
      iVar2 = iVar2 + 1;
      iVar1 = sk_num(st);
    } while (iVar2 < iVar1);
  }
  iVar1 = 1;
LAB_000341f8:
  sk_pop_free(st,X509_EXTENSION_free);
  return iVar1;
}

