
NETSCAPE_SPKI * NETSCAPE_SPKI_b64_decode(char *str,int len)

{
  undefined *puVar1;
  int iVar2;
  NETSCAPE_SPKI *pNVar3;
  int iVar4;
  int iVar5;
  int iStack_68;
  NETSCAPE_SPKI *pNStack_64;
  NETSCAPE_SPKI *pNStack_5c;
  int iStack_58;
  undefined *puStack_54;
  char *pcStack_50;
  char *pcStack_4c;
  NETSCAPE_SPKI *local_20;
  int local_1c;
  
  puStack_54 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (len < 1) {
    len = (*(code *)PTR_strlen_006a9a24)();
  }
  pNStack_5c = (NETSCAPE_SPKI *)(*(code *)PTR_CRYPTO_malloc_006a7008)(len + 1,"x509spki.c",0x58);
  if (pNStack_5c == (NETSCAPE_SPKI *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x81,0x41,"x509spki.c");
    pNVar3 = (NETSCAPE_SPKI *)0x0;
  }
  else {
    iVar2 = (*(code *)PTR_EVP_DecodeBlock_006a8aec)(pNStack_5c,str,len);
    if (iVar2 < 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x81,0x76,"x509spki.c");
      (*(code *)PTR_CRYPTO_free_006a6e88)(pNStack_5c);
      pNVar3 = (NETSCAPE_SPKI *)0x0;
    }
    else {
      local_20 = pNStack_5c;
      pNVar3 = (NETSCAPE_SPKI *)(*(code *)PTR_d2i_NETSCAPE_SPKI_006a8ecc)(0,&local_20,iVar2);
      (*(code *)PTR_CRYPTO_free_006a6e88)(pNStack_5c);
      pNStack_5c = pNVar3;
    }
  }
  if (local_1c == *(int *)puStack_54) {
    return pNVar3;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pcStack_50 = "encrypt";
  pNStack_64 = *(NETSCAPE_SPKI **)PTR___stack_chk_guard_006a9ae8;
  iStack_58 = len;
  pcStack_4c = str;
  iVar4 = (*(code *)PTR_i2d_NETSCAPE_SPKI_006a8ed0)();
  iVar5 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar4,"x509spki.c",0x70);
  pNVar3 = (NETSCAPE_SPKI *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar4 << 1,"x509spki.c",0x71);
  if ((iVar5 == 0) || (pNVar3 == (NETSCAPE_SPKI *)0x0)) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x82,0x41,"x509spki.c",0x73);
    pNVar3 = (NETSCAPE_SPKI *)0x0;
  }
  else {
    iStack_68 = iVar5;
    (*(code *)PTR_i2d_NETSCAPE_SPKI_006a8ed0)(iVar2,&iStack_68);
    (*(code *)PTR_EVP_EncodeBlock_006a8af8)(pNVar3,iVar5,iVar4);
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar5);
  }
  if (pNStack_64 != *(NETSCAPE_SPKI **)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return pNStack_64;
  }
  return pNVar3;
}
