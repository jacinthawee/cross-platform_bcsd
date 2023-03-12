
void engine_pkey_asn1_meths_free(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_GS_OFFSET;
  EVP_PKEY_ASN1_METHOD *local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (*(code **)(param_1 + 0x30) != (code *)0x0) {
    iVar3 = 0;
    iVar1 = (**(code **)(param_1 + 0x30))(param_1,0,&local_24,0);
    if (0 < iVar1) {
      do {
        while (iVar2 = (**(code **)(param_1 + 0x30))
                                 (param_1,&local_28,0,*(undefined4 *)(local_24 + iVar3 * 4)),
              iVar2 != 0) {
          iVar3 = iVar3 + 1;
          EVP_PKEY_asn1_free(local_28);
          if (iVar1 == iVar3) goto LAB_08115ff2;
        }
        iVar3 = iVar3 + 1;
      } while (iVar1 != iVar3);
    }
  }
LAB_08115ff2:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

