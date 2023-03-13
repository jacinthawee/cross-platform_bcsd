
int X509_set_version(X509 *x,long version)

{
  X509 *pXVar1;
  ASN1_BIT_STRING *pAVar2;
  int iVar3;
  X509_CINF *pXVar4;
  int iVar5;
  ASN1_STRING *pAVar6;
  int iVar7;
  int in_GS_OFFSET;
  undefined auStack_17 [7];
  int iStack_10;
  
  if (x == (X509 *)0x0) {
    return 0;
  }
  pXVar4 = x->cert_info;
  pXVar1 = (X509 *)pXVar4->version;
  if (pXVar1 == (X509 *)0x0) {
    pAVar6 = ASN1_STRING_type_new(2);
    pXVar4->version = pAVar6;
    if (pAVar6 == (ASN1_STRING *)0x0) {
      return 0;
    }
    pXVar1 = (X509 *)x->cert_info->version;
  }
  x = pXVar1;
  iStack_10 = *(int *)(in_GS_OFFSET + 0x14);
  x->sig_alg = (X509_ALGOR *)0x2;
  if ((int)x->cert_info < 5) {
    if (x->signature != (ASN1_BIT_STRING *)0x0) {
      CRYPTO_free(x->signature);
    }
    pAVar2 = (ASN1_BIT_STRING *)CRYPTO_malloc(5,"a_int.c",0x164);
    x->signature = pAVar2;
    if (pAVar2 != (ASN1_BIT_STRING *)0x0) {
      pAVar2->length = 0;
      *(undefined *)&pAVar2->type = 0;
      goto LAB_08138524;
    }
  }
  else {
LAB_08138524:
    pAVar2 = x->signature;
    if (pAVar2 != (ASN1_BIT_STRING *)0x0) {
      if (version < 0) {
        version = -version;
        x->sig_alg = (X509_ALGOR *)0x102;
LAB_0813853d:
        auStack_17[2] = (char)version;
        if (version >> 8 == 0) {
          iVar5 = 1;
LAB_081385fd:
          iVar3 = iVar5 + -1;
          *(undefined *)&pAVar2->length = auStack_17[iVar5 + 1];
          if (iVar5 != 1) {
            iVar7 = iVar5 + -3;
            *(undefined *)((int)&x->signature->length + 1) = auStack_17[iVar5];
            if (iVar7 != -1) goto LAB_08138584;
          }
        }
        else {
          auStack_17[3] = (char)((uint)version >> 8);
          if (version >> 0x10 == 0) {
            iVar5 = 2;
            goto LAB_081385fd;
          }
          auStack_17[4] = (undefined)((uint)version >> 0x10);
          if (version >> 0x18 == 0) {
            iVar5 = 3;
            goto LAB_081385fd;
          }
          auStack_17[5] = (undefined)((uint)version >> 0x18);
          *(undefined *)&pAVar2->length = auStack_17[5];
          *(undefined *)((int)&x->signature->length + 1) = auStack_17[4];
          iVar3 = 3;
          iVar7 = 1;
LAB_08138584:
          *(undefined *)((int)&x->signature->length + 2) = auStack_17[iVar7 + 2];
          if (iVar7 != 0) {
            *(char *)((int)&x->signature->length + 3) = (char)version;
          }
        }
        pXVar4 = (X509_CINF *)(iVar3 + 1);
      }
      else {
        if (version != 0) goto LAB_0813853d;
        pXVar4 = (X509_CINF *)0x0;
      }
      x->cert_info = pXVar4;
      iVar5 = 1;
      goto LAB_081385a8;
    }
  }
  ERR_put_error(0xd,0x76,0x41,"a_int.c",0x168);
  iVar5 = 0;
LAB_081385a8:
  if (iStack_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

