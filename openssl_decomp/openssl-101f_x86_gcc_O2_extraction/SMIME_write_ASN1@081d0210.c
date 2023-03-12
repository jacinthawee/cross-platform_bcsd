
int SMIME_write_ASN1(BIO *bio,ASN1_VALUE *val,BIO *data,int flags,int ctype_nid,int econt_nid,
                    stack_st_X509_ALGOR *mdalgs,ASN1_ITEM *it)

{
  void *pvVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  byte bVar5;
  ASN1_OBJECT **ppAVar6;
  char *pcVar7;
  EVP_MD *pEVar8;
  int iVar9;
  int iVar10;
  BIO *pBVar11;
  char *pcVar12;
  char *pcVar13;
  byte *pbVar14;
  byte *pbVar15;
  int iVar16;
  char *pcVar17;
  int in_GS_OFFSET;
  ASN1_VALUE *local_54;
  BIO *local_50;
  BIO *local_4c;
  undefined4 local_48;
  byte local_41 [32];
  byte local_21;
  int local_20;
  
  pcVar12 = "application/pkcs7-";
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((flags & 0x400U) != 0) {
    pcVar12 = "application/x-pkcs7-";
  }
  pcVar13 = "\n";
  if ((flags & 0x800U) != 0) {
    pcVar13 = "\r\n";
  }
  if (((flags & 0x40U) == 0) || (data == (BIO *)0x0)) {
    if (ctype_nid == 0x17) {
      pcVar17 = "enveloped-data";
      pcVar7 = "smime.p7m";
LAB_081d071a:
      BIO_printf(bio,"MIME-Version: 1.0%s",pcVar13);
      BIO_printf(bio,"Content-Disposition: attachment;");
      BIO_printf(bio," filename=\"%s\"%s",pcVar7,pcVar13);
      BIO_printf(bio,"Content-Type: %smime;",pcVar12);
      BIO_printf(bio," smime-type=%s;",pcVar17);
    }
    else {
      if (ctype_nid == 0x16) {
        if (econt_nid == 0xcc) {
          pcVar17 = "signed-receipt";
          pcVar7 = "smime.p7m";
        }
        else {
          pcVar17 = "signed-data";
          pcVar7 = "smime.p7m";
          iVar16 = sk_num(&mdalgs->stack);
          if (iVar16 < 0) {
            pcVar17 = "certs-only";
          }
        }
        goto LAB_081d071a;
      }
      if (ctype_nid == 0x312) {
        pcVar17 = "compressed-data";
        pcVar7 = "smime.p7z";
        goto LAB_081d071a;
      }
      BIO_printf(bio,"MIME-Version: 1.0%s",pcVar13);
      BIO_printf(bio,"Content-Disposition: attachment;");
      pcVar7 = "smime.p7m";
      BIO_printf(bio," filename=\"%s\"%s","smime.p7m",pcVar13);
      BIO_printf(bio,"Content-Type: %smime;",pcVar12);
    }
    pcVar12 = pcVar13;
    BIO_printf(bio," name=\"%s\"%s",pcVar7,pcVar13);
    BIO_printf(bio,"Content-Transfer-Encoding: base64%s%s",pcVar13,pcVar13);
    iVar16 = B64_write_ASN1(flags,it);
    if (iVar16 != 0) {
      BIO_printf(bio,"%s",pcVar13,pcVar12);
      iVar16 = 1;
      goto LAB_081d049c;
    }
  }
  else {
    RAND_pseudo_bytes(local_41,0x20);
    pbVar14 = local_41;
    do {
      bVar4 = *pbVar14 & 0xf;
      bVar5 = bVar4 + 0x37;
      if (bVar4 < 10) {
        bVar5 = bVar4 + 0x30;
      }
      pbVar15 = pbVar14 + 1;
      *pbVar14 = bVar5;
      pbVar14 = pbVar15;
    } while (&local_21 != pbVar15);
    local_21 = 0;
    BIO_printf(bio,"MIME-Version: 1.0%s",pcVar13);
    BIO_printf(bio,"Content-Type: multipart/signed;");
    BIO_printf(bio," protocol=\"%ssignature\";",pcVar12);
    bVar2 = false;
    BIO_puts(bio," micalg=\"");
    bVar3 = false;
    for (iVar16 = 0; iVar10 = sk_num(&mdalgs->stack), iVar16 < iVar10; iVar16 = iVar16 + 1) {
      if (bVar2) {
        BIO_write(bio,",",1);
      }
      ppAVar6 = (ASN1_OBJECT **)sk_value(&mdalgs->stack,iVar16);
      iVar10 = OBJ_obj2nid(*ppAVar6);
      pcVar7 = OBJ_nid2sn(iVar10);
      pEVar8 = EVP_get_digestbyname(pcVar7);
      if ((pEVar8 == (EVP_MD *)0x0) || (pEVar8->md_ctrl == (_func_1085 *)0x0)) {
LAB_081d04dd:
        if (iVar10 == 0x2a0) {
          bVar2 = true;
          BIO_puts(bio,"sha-256");
        }
        else if (iVar10 < 0x2a1) {
          if (iVar10 == 4) {
            bVar2 = true;
            BIO_puts(bio,"md5");
          }
          else {
            if (iVar10 != 0x40) goto LAB_081d0678;
            bVar2 = true;
            BIO_puts(bio,"sha1");
          }
        }
        else if (iVar10 == 0x2a2) {
          bVar2 = true;
          BIO_puts(bio,"sha-512");
        }
        else if (iVar10 < 0x2a2) {
          bVar2 = true;
          BIO_puts(bio,"sha-384");
        }
        else {
          if (iVar10 == 0x329) {
            BIO_puts(bio,"gostr3411-94");
            break;
          }
LAB_081d0678:
          bVar2 = false;
          if (!bVar3) {
            bVar2 = true;
            BIO_puts(bio,"unknown");
            bVar3 = true;
          }
        }
      }
      else {
        iVar9 = (*pEVar8->md_ctrl)((EVP_MD_CTX *)0x0,2,0,&local_50);
        if (iVar9 < 1) {
          if (iVar9 == -2) goto LAB_081d04dd;
          break;
        }
        bVar2 = true;
        BIO_puts(bio,(char *)local_50);
        CRYPTO_free(local_50);
      }
    }
    BIO_printf(bio,"\"; boundary=\"----%s\"%s%s",local_41,pcVar13,pcVar13);
    BIO_printf(bio,"This is an S/MIME signed message%s%s",pcVar13,pcVar13);
    BIO_printf(bio,"------%s%s",local_41,pcVar13);
    local_54 = val;
    if ((flags & 0x8040U) != 0x40) {
      SMIME_crlf_copy(data,bio,flags);
LAB_081d07b7:
      BIO_printf(bio,"%s------%s%s",pcVar13,local_41,pcVar13);
      BIO_printf(bio,"Content-Type: %ssignature;",pcVar12);
      BIO_printf(bio," name=\"smime.p7s\"%s",pcVar13);
      BIO_printf(bio,"Content-Transfer-Encoding: base64%s",pcVar13);
      BIO_printf(bio,"Content-Disposition: attachment;");
      BIO_printf(bio," filename=\"smime.p7s\"%s%s",pcVar13,pcVar13);
      B64_write_ASN1(0,it);
      BIO_printf(bio,"%s------%s--%s%s",pcVar13,local_41,pcVar13,pcVar13);
      iVar16 = 1;
      goto LAB_081d049c;
    }
    pvVar1 = it->funcs;
    if ((pvVar1 == (void *)0x0) || (*(code **)((int)pvVar1 + 0x10) == (code *)0x0)) {
      ERR_put_error(0xd,0xd6,0xca,"asn_mime.c",0x18a);
    }
    else {
      local_50 = bio;
      local_4c = (BIO *)0x0;
      local_48 = 0;
      iVar16 = (**(code **)((int)pvVar1 + 0x10))(0xc,&local_54,it,&local_50);
      if (0 < iVar16) {
        SMIME_crlf_copy(data,local_4c,flags);
        iVar16 = (**(code **)((int)pvVar1 + 0x10))(0xd,&local_54,it,&local_50);
        while (bio != local_4c) {
          pBVar11 = BIO_pop(local_4c);
          BIO_free(local_4c);
          local_4c = pBVar11;
        }
        if (0 < iVar16) goto LAB_081d07b7;
      }
    }
  }
  iVar16 = 0;
LAB_081d049c:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar16;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

