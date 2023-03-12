
X509_NAME *
build_subject(X509_REQ *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  X509_NAME *name;
  X509_NAME *pXVar1;
  
  name = (X509_NAME *)parse_name(param_2,param_3,param_4,param_4,param_4);
  if (name != (X509_NAME *)0x0) {
    pXVar1 = (X509_NAME *)X509_REQ_set_subject_name(param_1,name);
    if (pXVar1 != (X509_NAME *)0x0) {
      pXVar1 = (X509_NAME *)0x1;
    }
    X509_NAME_free(name);
    name = pXVar1;
  }
  return name;
}

