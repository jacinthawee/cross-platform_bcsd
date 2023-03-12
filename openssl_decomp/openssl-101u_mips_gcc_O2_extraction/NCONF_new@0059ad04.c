
CONF * NCONF_new(CONF_METHOD *meth)

{
  CONF *pCVar1;
  
  if (meth == (CONF_METHOD *)0x0) {
    meth = NCONF_default();
  }
  pCVar1 = (*meth->create)(meth);
  if (pCVar1 == (CONF *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x6f,0x41,"conf_lib.c",0xed);
  }
  return pCVar1;
}

