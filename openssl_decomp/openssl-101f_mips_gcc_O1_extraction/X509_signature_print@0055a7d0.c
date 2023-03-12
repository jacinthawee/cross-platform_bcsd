
int X509_signature_print(BIO *bp,X509_ALGOR *alg,ASN1_STRING *sig)

{
  int iVar1;
  uint uVar2;
  EVP_PKEY_ASN1_METHOD *pEVar3;
  char cVar5;
  int iVar4;
  ASN1_OBJECT *pAVar6;
  char *pcVar7;
  ASN1_OBJECT *pAVar8;
  int iVar9;
  undefined *puVar10;
  char *pcVar11;
  int unaff_s3;
  undefined4 unaff_s4;
  ASN1_OBJECT *unaff_s6;
  int iVar12;
  int unaff_s7;
  ASN1_OBJECT aAStack_d4 [3];
  int iStack_84;
  X509_ALGOR *pXStack_80;
  BIO *pBStack_7c;
  ASN1_STRING *pAStack_78;
  int iStack_74;
  undefined4 uStack_70;
  undefined *puStack_6c;
  ASN1_OBJECT *pAStack_68;
  int iStack_64;
  int local_34;
  undefined auStack_30 [4];
  int local_2c;
  
  puStack_6c = PTR___stack_chk_guard_006aabf0;
  pcVar7 = "    Signature Algorithm: ";
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar1 = (*(code *)PTR_BIO_puts_006a8058)();
  if (iVar1 < 1) {
LAB_0055a924:
    uVar2 = 0;
  }
  else {
    pcVar7 = (char *)alg->algorithm;
    iVar1 = i2a_ASN1_OBJECT(bp,(ASN1_OBJECT *)pcVar7);
    if (iVar1 < 1) goto LAB_0055a924;
    iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(alg->algorithm);
    if ((((iVar1 == 0) ||
         (iVar1 = (*(code *)PTR_OBJ_find_sigid_algs_006a9468)(iVar1,auStack_30,&local_34),
         iVar1 == 0)) ||
        (pEVar3 = EVP_PKEY_asn1_find((ENGINE **)0x0,local_34), pEVar3 == (EVP_PKEY_ASN1_METHOD *)0x0
        )) || (*(code **)(pEVar3 + 0x50) == (code *)0x0)) {
      if (sig == (ASN1_STRING *)0x0) {
        pcVar7 = "\n";
        iVar1 = (*(code *)PTR_BIO_puts_006a8058)(bp);
        uVar2 = (uint)(0 < iVar1);
      }
      else {
        unaff_s3 = sig->length;
        alg = (X509_ALGOR *)sig->data;
        if (0 < unaff_s3) {
          unaff_s7 = 0;
          unaff_s6 = (ASN1_OBJECT *)0x63bac8;
          sig = (ASN1_STRING *)0x667598;
          unaff_s4 = 0x660000;
          while( true ) {
            if (unaff_s7 == (unaff_s7 / 0x12) * 0x12) {
              pcVar7 = (char *)unaff_s6;
              iVar1 = (*(code *)PTR_BIO_write_006a7f14)(bp,"\n",1);
              if (iVar1 < 1) goto LAB_0055a924;
              pcVar7 = &DAT_00000009;
              iVar1 = (*(code *)PTR_BIO_indent_006a97d0)(bp,9,9);
              if (iVar1 < 1) goto LAB_0055a924;
            }
            unaff_s7 = unaff_s7 + 1;
            if (unaff_s3 == unaff_s7) break;
            pcVar7 = "%02x%s";
            iVar1 = (*(code *)PTR_BIO_printf_006a7f38)
                              (bp,"%02x%s",*(undefined *)&alg->algorithm,":");
            if (iVar1 < 1) goto LAB_0055a924;
            alg = (X509_ALGOR *)((int)&alg->algorithm + 1);
          }
          pcVar7 = "%02x%s";
          iVar1 = (*(code *)PTR_BIO_printf_006a7f38)(bp,"%02x%s",*(undefined *)&alg->algorithm,"");
          if (0 < iVar1) goto LAB_0055a9e4;
          goto LAB_0055a924;
        }
LAB_0055a9e4:
        pcVar7 = "\n";
        iVar1 = (*(code *)PTR_BIO_write_006a7f14)(bp,"\n",1);
        uVar2 = (uint)(iVar1 == 1);
      }
    }
    else {
      pcVar7 = (char *)alg;
      uVar2 = (**(code **)(pEVar3 + 0x50))(bp,alg,sig,9);
    }
  }
  if (local_2c == *(int *)puStack_6c) {
    return uVar2;
  }
  iVar1 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar10 = PTR___stack_chk_guard_006aabf0;
  iStack_84 = *(int *)PTR___stack_chk_guard_006aabf0;
  pAVar8 = (ASN1_OBJECT *)pcVar7;
  pXStack_80 = alg;
  pBStack_7c = bp;
  pAStack_78 = sig;
  iStack_74 = unaff_s3;
  uStack_70 = unaff_s4;
  pAStack_68 = unaff_s6;
  iStack_64 = unaff_s7;
  if ((ASN1_OBJECT *)pcVar7 == (ASN1_OBJECT *)0x0) {
LAB_0055ab8c:
    uVar2 = 0;
  }
  else {
    pAVar6 = *(ASN1_OBJECT **)pcVar7;
    pcVar11 = *(char **)((int)pcVar7 + 8);
    if (0 < (int)pAVar6) {
      iVar12 = 0;
      iVar4 = 0;
      do {
        while( true ) {
          cVar5 = *pcVar11;
          if (cVar5 == '\x7f') {
            cVar5 = '.';
          }
          else if (((cVar5 < ' ') && (cVar5 != '\n')) && (cVar5 != '\r')) {
            cVar5 = '.';
          }
          iVar9 = iVar4 + 1;
          *(char *)((int)&aAStack_d4[0].sn + iVar4) = cVar5;
          if (0x4f < iVar9) break;
          iVar12 = iVar12 + 1;
          pcVar11 = pcVar11 + 1;
          iVar4 = iVar9;
          if ((int)pAVar6 <= iVar12) goto LAB_0055ab24;
        }
        pAVar8 = aAStack_d4;
        iVar4 = (*(code *)PTR_BIO_write_006a7f14)(iVar1);
        if (iVar4 < 1) goto LAB_0055ab8c;
        pAVar6 = *(ASN1_OBJECT **)pcVar7;
        iVar12 = iVar12 + 1;
        iVar9 = 0;
        pcVar11 = pcVar11 + 1;
        iVar4 = iVar9;
      } while (iVar12 < (int)pAVar6);
LAB_0055ab24:
      if (iVar9 != 0) {
        pAVar8 = aAStack_d4;
        iVar1 = (*(code *)PTR_BIO_write_006a7f14)(iVar1);
        uVar2 = (uint)(0 < iVar1);
        goto LAB_0055ab40;
      }
    }
    uVar2 = 1;
  }
LAB_0055ab40:
  if (iStack_84 == *(int *)puVar10) {
    return uVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pAVar6 = (ASN1_OBJECT *)pAVar8->sn;
  if (((((int)pAVar6 < 0xc) || (pcVar7 = (char *)pAVar8->nid, 9 < (byte)(*pcVar7 - 0x30U))) ||
      ((9 < (byte)(pcVar7[1] - 0x30U) ||
       ((((9 < (byte)(pcVar7[2] - 0x30U) || (9 < (byte)(pcVar7[3] - 0x30U))) ||
         (9 < (byte)(pcVar7[4] - 0x30U))) ||
        ((9 < (byte)(pcVar7[5] - 0x30U) || (9 < (byte)(pcVar7[6] - 0x30U))))))))) ||
     (((9 < (byte)(pcVar7[7] - 0x30U) ||
       ((9 < (byte)(pcVar7[8] - 0x30U) || (9 < (byte)(pcVar7[9] - 0x30U))))) ||
      ((9 < (byte)(pcVar7[10] - 0x30U) ||
       ((9 < (byte)(pcVar7[0xb] - 0x30U) ||
        (0xb < ((pcVar7[4] + -0x30) * 10 + (int)pcVar7[5]) - 0x31U)))))))) {
    (*(code *)PTR_BIO_write_006a7f14)();
    return 0;
  }
  if ((((0xd < (int)pAVar6) && ((byte)(pcVar7[0xc] - 0x30U) < 10)) &&
      ((byte)(pcVar7[0xd] - 0x30U) < 10)) &&
     (((pAVar6 != (ASN1_OBJECT *)0xe && (pcVar7[0xe] == '.')) &&
      ((pAVar6 != (ASN1_OBJECT *)0xf && (pcVar11 = pcVar7 + 0x10, (byte)(pcVar7[0xf] - 0x30U) < 10))
      )))) {
    puVar10 = (undefined *)0x1;
    do {
      puVar10 = puVar10 + 1;
      if (puVar10 == (undefined *)((int)&pAVar6[-1].nid + 2)) break;
      cVar5 = *pcVar11;
      pcVar11 = pcVar11 + 1;
    } while ((byte)(cVar5 - 0x30U) < 10);
  }
  iVar1 = (*(code *)PTR_BIO_printf_006a7f38)();
  return (uint)(0 < iVar1);
}

