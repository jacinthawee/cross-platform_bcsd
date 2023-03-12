
CONF * NCONF_new(CONF_METHOD *meth)

{
  CONF *pCVar1;
  
  if (meth == (CONF_METHOD *)0x0) {
    meth = NCONF_default();
  }
  pCVar1 = (*meth->create)(meth);
  if (pCVar1 == (CONF *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x6f,0x41,"conf_lib.c",0xf4);
  }
  return pCVar1;
}

