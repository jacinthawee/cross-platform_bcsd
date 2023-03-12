
undefined4 tls1_process_sigalgs(int *param_1,int param_2,int param_3)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  
  if ((*param_1 >> 8 != 3) || (*param_1 < 0x303)) {
    return 1;
  }
  iVar7 = param_1[0x26];
  if (iVar7 == 0) {
    return 0;
  }
  *(undefined4 *)(iVar7 + 0x50) = 0;
  *(undefined4 *)(iVar7 + 0x44) = 0;
  *(undefined4 *)(iVar7 + 0x38) = 0;
  *(undefined4 *)(iVar7 + 0x74) = 0;
  if (0 < param_3) {
    pcVar5 = (char *)(param_2 + 1);
    do {
      cVar1 = *pcVar5;
      iVar6 = 2;
      if ((((cVar1 == '\x02') || (iVar6 = 5, cVar1 == '\x03')) || (iVar6 = 1, cVar1 == '\x01')) &&
         (*(int *)(iVar7 + iVar6 * 0xc + 0x38) == 0)) {
        switch(pcVar5[-1]) {
        default:
          goto LAB_004980b8;
        case '\x02':
          iVar3 = (*(code *)PTR_EVP_sha1_006a86c4)();
          break;
        case '\x03':
          iVar3 = (*(code *)PTR_EVP_sha224_006a9304)();
          break;
        case '\x04':
          iVar3 = (*(code *)PTR_EVP_sha256_006a916c)();
          break;
        case '\x05':
          iVar3 = (*(code *)PTR_EVP_sha384_006a9308)();
          break;
        case '\x06':
          iVar3 = (*(code *)PTR_EVP_sha512_006a9300)();
        }
        if ((iVar3 != 0) && (*(int *)(iVar7 + iVar6 * 0xc + 0x38) = iVar3, iVar6 == 1)) {
          *(int *)(iVar7 + 0x38) = iVar3;
        }
      }
LAB_004980b8:
      pcVar5 = pcVar5 + 2;
    } while (pcVar5 != (char *)(param_2 + (param_3 - 1U & 0xfffffffe) + 3));
    if (*(int *)(iVar7 + 0x50) != 0) goto LAB_00498118;
  }
  uVar4 = (*(code *)PTR_EVP_sha1_006a86c4)();
  *(undefined4 *)(iVar7 + 0x50) = uVar4;
LAB_00498118:
  if (*(int *)(iVar7 + 0x44) == 0) {
    uVar4 = (*(code *)PTR_EVP_sha1_006a86c4)();
    puVar2 = PTR_EVP_sha1_006a86c4;
    *(undefined4 *)(iVar7 + 0x44) = uVar4;
    uVar4 = (*(code *)puVar2)();
    *(undefined4 *)(iVar7 + 0x38) = uVar4;
  }
  if (*(int *)(iVar7 + 0x74) == 0) {
    uVar4 = (*(code *)PTR_EVP_sha1_006a86c4)();
    *(undefined4 *)(iVar7 + 0x74) = uVar4;
  }
  return 1;
}

