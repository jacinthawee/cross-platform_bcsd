
int X509_signature_print(BIO *bp,X509_ALGOR *alg,ASN1_STRING *sig)

{
  uchar *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  EVP_PKEY_ASN1_METHOD *pEVar5;
  int iVar6;
  int in_GS_OFFSET;
  int local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = BIO_puts(bp,"    Signature Algorithm: ");
  if ((0 < iVar2) && (iVar2 = i2a_ASN1_OBJECT(bp,alg->algorithm), 0 < iVar2)) {
    iVar2 = OBJ_obj2nid(alg->algorithm);
    if ((iVar2 != 0) &&
       (((iVar2 = OBJ_find_sigid_algs(iVar2,&local_24,&local_28), iVar2 != 0 &&
         (pEVar5 = EVP_PKEY_asn1_find((ENGINE **)0x0,local_28),
         pEVar5 != (EVP_PKEY_ASN1_METHOD *)0x0)) && (*(code **)(pEVar5 + 0x50) != (code *)0x0)))) {
      uVar4 = (**(code **)(pEVar5 + 0x50))(bp,alg,sig,9,0);
      goto LAB_081424da;
    }
    if (sig == (ASN1_STRING *)0x0) {
      iVar2 = BIO_puts(bp,"\n");
      uVar4 = (uint)(0 < iVar2);
      goto LAB_081424da;
    }
    iVar2 = sig->length;
    puVar1 = sig->data;
    iVar6 = 0;
    if (iVar2 < 1) {
LAB_08142510:
      iVar2 = BIO_write(bp,&DAT_081f15cb,1);
      uVar4 = (uint)(iVar2 == 1);
      goto LAB_081424da;
    }
    do {
      if ((iVar6 == (iVar6 / 0x12) * 0x12) &&
         ((iVar3 = BIO_write(bp,&DAT_081f15cb,1), iVar3 < 1 ||
          (iVar3 = BIO_indent(bp,9,9), iVar3 < 1)))) break;
      if (iVar2 == iVar6 + 1) {
        iVar2 = BIO_printf(bp,"%02x%s",(uint)puVar1[iVar6],&DAT_081eca46);
        if (0 < iVar2) goto LAB_08142510;
        break;
      }
      iVar3 = BIO_printf(bp,"%02x%s",(uint)puVar1[iVar6],":");
      iVar6 = iVar6 + 1;
    } while (0 < iVar3);
  }
  uVar4 = 0;
LAB_081424da:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}

