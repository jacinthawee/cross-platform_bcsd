
undefined8 __regparm3
build_subject(X509_REQ *param_1_00,undefined4 param_2,undefined4 param_3,undefined4 param_1)

{
  X509_NAME *name;
  int iVar1;
  undefined4 uStack_c;
  
  name = (X509_NAME *)parse_name(param_2,param_3,param_1);
  if (name == (X509_NAME *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = X509_REQ_set_subject_name(param_1_00,name);
    if (iVar1 == 0) {
      X509_NAME_free(name);
    }
    else {
      iVar1 = 1;
      X509_NAME_free(name);
    }
  }
  return CONCAT44(uStack_c,iVar1);
}

