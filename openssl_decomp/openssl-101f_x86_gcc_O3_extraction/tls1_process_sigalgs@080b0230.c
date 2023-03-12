
undefined4 tls1_process_sigalgs(int *param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  EVP_MD *pEVar3;
  char *pcVar4;
  int iVar5;
  
  if (*param_1 >> 8 != 3) {
    return 1;
  }
  if (*param_1 < 0x303) {
    return 1;
  }
  iVar2 = param_1[0x26];
  if (iVar2 == 0) {
    return 0;
  }
  *(undefined4 *)(iVar2 + 0x50) = 0;
  *(undefined4 *)(iVar2 + 0x44) = 0;
  *(undefined4 *)(iVar2 + 0x38) = 0;
  *(undefined4 *)(iVar2 + 0x74) = 0;
  if (0 < param_3) {
    pcVar4 = (char *)(param_2 + 1);
    do {
      cVar1 = *pcVar4;
      if (cVar1 == '\x02') {
        iVar5 = 2;
LAB_080b02cb:
        if (*(int *)(iVar2 + 0x38 + iVar5 * 0xc) == 0) {
          switch(pcVar4[-1]) {
          default:
            goto switchD_080b02e0_caseD_0;
          case '\x02':
            pEVar3 = EVP_sha1();
            break;
          case '\x03':
            pEVar3 = EVP_sha224();
            break;
          case '\x04':
            pEVar3 = EVP_sha256();
            break;
          case '\x05':
            pEVar3 = EVP_sha384();
            break;
          case '\x06':
            pEVar3 = EVP_sha512();
          }
          if ((pEVar3 != (EVP_MD *)0x0) &&
             (*(EVP_MD **)(iVar2 + 0x38 + iVar5 * 0xc) = pEVar3, iVar5 == 1)) {
            *(EVP_MD **)(iVar2 + 0x38) = pEVar3;
          }
        }
      }
      else {
        if (cVar1 == '\x03') {
          iVar5 = 5;
          goto LAB_080b02cb;
        }
        if (cVar1 == '\x01') {
          iVar5 = 1;
          goto LAB_080b02cb;
        }
      }
switchD_080b02e0_caseD_0:
      pcVar4 = pcVar4 + 2;
    } while (pcVar4 != (char *)(param_2 + 3 + (param_3 - 1U & 0xfffffffe)));
    if (*(int *)(iVar2 + 0x50) != 0) goto LAB_080b02f7;
  }
  pEVar3 = EVP_sha1();
  *(EVP_MD **)(iVar2 + 0x50) = pEVar3;
LAB_080b02f7:
  if (*(int *)(iVar2 + 0x44) == 0) {
    pEVar3 = EVP_sha1();
    *(EVP_MD **)(iVar2 + 0x44) = pEVar3;
    pEVar3 = EVP_sha1();
    *(EVP_MD **)(iVar2 + 0x38) = pEVar3;
  }
  if (*(int *)(iVar2 + 0x74) == 0) {
    pEVar3 = EVP_sha1();
    *(EVP_MD **)(iVar2 + 0x74) = pEVar3;
  }
  return 1;
}

