
int X509_ocspid_print(BIO *bp,X509 *x)

{
  undefined uVar1;
  int iVar2;
  int *piVar3;
  uchar *puVar4;
  EVP_MD *pEVar5;
  ASN1_BIT_STRING *pAVar6;
  int iVar7;
  char *pcVar8;
  int *in_a2;
  undefined *puVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  uchar *local_44;
  int local_40 [5];
  int local_2c;
  
  puVar9 = PTR___stack_chk_guard_006aabf0;
  pcVar8 = "        Subject OCSP hash: ";
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_BIO_printf_006a7f38)();
  if (0 < iVar2) {
    piVar3 = (int *)i2d_X509_NAME(x->cert_info->subject,(uchar **)0x0);
    in_a2 = (int *)0x103;
    pcVar8 = "t_x509.c";
    puVar4 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(piVar3,"t_x509.c",0x103);
    local_44 = puVar4;
    if (puVar4 != (uchar *)0x0) {
      piVar11 = local_40;
      i2d_X509_NAME(x->cert_info->subject,&local_44);
      pEVar5 = EVP_sha1();
      in_a2 = piVar11;
      iVar2 = (*(code *)PTR_EVP_Digest_006a8b04)(puVar4,piVar3,piVar11,0,pEVar5,0);
      pcVar8 = (char *)piVar3;
      if (iVar2 == 0) {
LAB_0055a5d0:
        (*(code *)PTR_CRYPTO_free_006a7f88)(puVar4);
        iVar2 = 0;
        goto LAB_0055a594;
      }
      piVar3 = piVar11;
      do {
        in_a2 = (int *)(uint)*(byte *)piVar3;
        pcVar8 = &DAT_00635448;
        iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(bp,&DAT_00635448,in_a2);
        if (iVar2 < 1) goto LAB_0055a5d0;
        piVar3 = (int *)((int)piVar3 + 1);
      } while (&local_2c != piVar3);
      (*(code *)PTR_CRYPTO_free_006a7f88)(puVar4);
      pcVar8 = "\n        Public key OCSP hash: ";
      iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(bp);
      if (0 < iVar2) {
        pAVar6 = x->cert_info->key->public_key;
        puVar4 = pAVar6->data;
        pcVar8 = (char *)pAVar6->length;
        pEVar5 = EVP_sha1();
        in_a2 = piVar11;
        iVar2 = (*(code *)PTR_EVP_Digest_006a8b04)(puVar4,pcVar8,piVar11,0,pEVar5,0);
        if (iVar2 != 0) {
          do {
            in_a2 = (int *)(uint)*(byte *)piVar11;
            pcVar8 = &DAT_00635448;
            iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(bp,&DAT_00635448,in_a2);
            if (iVar2 < 1) goto LAB_0055a590;
            piVar11 = (int *)((int)piVar11 + 1);
          } while (&local_2c != piVar11);
          pcVar8 = "\n";
          (*(code *)PTR_BIO_printf_006a7f38)(bp);
          iVar2 = 1;
          goto LAB_0055a594;
        }
      }
    }
  }
LAB_0055a590:
  iVar2 = 0;
LAB_0055a594:
  if (local_2c == *(int *)puVar9) {
    return iVar2;
  }
  iVar2 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar10 = *(int *)pcVar8;
  puVar9 = *(undefined **)((int)pcVar8 + 8);
  if (0 < iVar10) {
    iVar12 = 0;
    while( true ) {
      if (iVar12 == (iVar12 / 0x12) * 0x12) {
        iVar7 = (*(code *)PTR_BIO_write_006a7f14)(iVar2,"\n",1);
        if (iVar7 < 1) {
          return 0;
        }
        iVar7 = (*(code *)PTR_BIO_indent_006a97d0)(iVar2,in_a2,in_a2);
        if (iVar7 < 1) {
          return 0;
        }
      }
      iVar12 = iVar12 + 1;
      uVar1 = *puVar9;
      if (iVar10 == iVar12) break;
      puVar9 = puVar9 + 1;
      iVar7 = (*(code *)PTR_BIO_printf_006a7f38)(iVar2,"%02x%s",uVar1,":");
      if (iVar7 < 1) {
        return 0;
      }
    }
    iVar10 = (*(code *)PTR_BIO_printf_006a7f38)(iVar2,"%02x%s",uVar1,"");
    if (iVar10 < 1) {
      return 0;
    }
  }
  iVar2 = (*(code *)PTR_BIO_write_006a7f14)(iVar2,"\n",1);
  return (uint)(iVar2 == 1);
}

