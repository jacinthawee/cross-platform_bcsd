
undefined4 ssl3_cbc_record_digest_supported(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)();
  iVar2 = (*(code *)PTR_EVP_MD_type_006a84cc)(uVar1);
  if (iVar2 != 0x40) {
    if (iVar2 < 0x41) {
      if (iVar2 != 4) {
        return 0;
      }
    }
    else if (3 < iVar2 - 0x2a0U) {
      return 0;
    }
  }
  return 1;
}

