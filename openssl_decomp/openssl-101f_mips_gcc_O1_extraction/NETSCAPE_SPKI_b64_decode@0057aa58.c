
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
  
  puStack_54 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (len < 1) {
    len = (*(code *)PTR_strlen_006aab30)();
  }
  pNStack_5c = (NETSCAPE_SPKI *)(*(code *)PTR_CRYPTO_malloc_006a8108)(len + 1,"x509spki.c",0x55);
  if (pNStack_5c == (NETSCAPE_SPKI *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x81,0x41,"x509spki.c");
    pNVar3 = (NETSCAPE_SPKI *)0x0;
  }
  else {
    iVar2 = (*(code *)PTR_EVP_DecodeBlock_006a9c08)(pNStack_5c,str,len);
    if (iVar2 < 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x81,0x76,"x509spki.c");
      (*(code *)PTR_CRYPTO_free_006a7f88)(pNStack_5c);
      pNVar3 = (NETSCAPE_SPKI *)0x0;
    }
    else {
      local_20 = pNStack_5c;
      pNVar3 = (NETSCAPE_SPKI *)(*(code *)PTR_d2i_NETSCAPE_SPKI_006a9fe8)(0,&local_20,iVar2);
      (*(code *)PTR_CRYPTO_free_006a7f88)(pNStack_5c);
      pNStack_5c = pNVar3;
    }
  }
  if (local_1c == *(int *)puStack_54) {
    return pNVar3;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pcStack_50 = "7 datafinal";
  pNStack_64 = *(NETSCAPE_SPKI **)PTR___stack_chk_guard_006aabf0;
  iStack_58 = len;
  pcStack_4c = str;
  iVar4 = (*(code *)PTR_i2d_NETSCAPE_SPKI_006a9fec)();
  iVar5 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar4,"x509spki.c",0x6e);
  pNVar3 = (NETSCAPE_SPKI *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar4 << 1,"x509spki.c",0x6f);
  if ((iVar5 == 0) || (pNVar3 == (NETSCAPE_SPKI *)0x0)) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x82,0x41,"x509spki.c",0x71);
    pNVar3 = (NETSCAPE_SPKI *)0x0;
  }
  else {
    iStack_68 = iVar5;
    (*(code *)PTR_i2d_NETSCAPE_SPKI_006a9fec)(iVar2,&iStack_68);
    (*(code *)PTR_EVP_EncodeBlock_006a9c14)(pNVar3,iVar5,iVar4);
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar5);
  }
  if (pNStack_64 != *(NETSCAPE_SPKI **)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    return pNStack_64;
  }
  return pNVar3;
}

