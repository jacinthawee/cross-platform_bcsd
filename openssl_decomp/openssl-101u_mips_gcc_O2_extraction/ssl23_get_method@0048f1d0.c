
SSL_METHOD * ssl23_get_method(int param_1)

{
  SSL_METHOD *pSVar1;
  
  if (param_1 == 0x300) {
                    /* WARNING: Could not recover jumptable at 0x0048f210. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pSVar1 = (SSL_METHOD *)(*(code *)PTR_SSLv3_method_006a8174)();
    return pSVar1;
  }
  if (param_1 == 0x301) {
    pSVar1 = TLSv1_method();
    return pSVar1;
  }
  if (param_1 == 0x302) {
    pSVar1 = TLSv1_1_method();
    return pSVar1;
  }
  if (param_1 == 0x303) {
    pSVar1 = TLSv1_2_method();
    return pSVar1;
  }
  return (SSL_METHOD *)0x0;
}

