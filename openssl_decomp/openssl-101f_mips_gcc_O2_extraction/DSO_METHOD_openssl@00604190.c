
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DSO_METHOD * DSO_METHOD_openssl(void)

{
  DSO_METHOD *pDVar1;
  
  pDVar1 = (DSO_METHOD *)(*(code *)PTR_DSO_METHOD_dlfcn_006aa890)();
  return pDVar1;
}

