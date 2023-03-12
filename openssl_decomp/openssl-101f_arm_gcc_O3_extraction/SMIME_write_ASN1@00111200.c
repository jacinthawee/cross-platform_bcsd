
int SMIME_write_ASN1(BIO *bio,ASN1_VALUE *val,BIO *data,int flags,int ctype_nid,int econt_nid,
                    stack_st_X509_ALGOR *mdalgs,ASN1_ITEM *it)

{
  bool bVar1;
  bool bVar2;
  ASN1_OBJECT **ppAVar3;
  char *pcVar4;
  EVP_MD *pEVar5;
  int iVar6;
  int iVar7;
  BIO *pBVar8;
  byte bVar9;
  byte bVar10;
  char *pcVar11;
  byte *pbVar12;
  byte *pbVar13;
  int iVar14;
  char *pcVar15;
  void *pvVar16;
  char *pcVar17;
  char cVar18;
  ASN1_VALUE *local_60;
  BIO *local_5c;
  BIO *local_58;
  undefined4 local_54;
  byte local_50 [32];
  byte local_30 [4];
  int local_2c;
  
  pcVar11 = "application/x-pkcs7-";
  if ((flags & 0x400U) == 0) {
    pcVar11 = "application/pkcs7-";
  }
  pcVar17 = "\n";
  if ((flags & 0x800U) != 0) {
    pcVar17 = "\r\n";
  }
  local_2c = __TMC_END__;
  if (((flags & 0x40U) == 0) || (data == (BIO *)0x0)) {
    if (ctype_nid == 0x17) {
      pcVar15 = "smime.p7m";
      pcVar4 = "enveloped-data";
LAB_00111570:
      BIO_printf(bio,"MIME-Version: 1.0%s",pcVar17);
      BIO_printf(bio,"Content-Disposition: attachment;");
      BIO_printf(bio," filename=\"%s\"%s",pcVar15,pcVar17);
      BIO_printf(bio,"Content-Type: %smime;",pcVar11);
      BIO_printf(bio," smime-type=%s;",pcVar4);
    }
    else {
      if (ctype_nid == 0x16) {
        cVar18 = 0xcb < (uint)econt_nid;
        if (econt_nid == 0xcc) {
          pcVar15 = "smime.p7m";
          pcVar4 = "signed-receipt";
        }
        else {
          iVar14 = sk_num(&mdalgs->stack);
          pcVar15 = "smime.p7m";
          pcVar4 = (char *)(iVar14 >> 0x20 & 0x176698);
          if (cVar18 == '\0') {
            pcVar4 = "signed-data";
          }
        }
        goto LAB_00111570;
      }
      if (ctype_nid == 0x312) {
        pcVar15 = "smime.p7z";
        pcVar4 = "compressed-data";
        goto LAB_00111570;
      }
      BIO_printf(bio,"MIME-Version: 1.0%s",pcVar17);
      BIO_printf(bio,"Content-Disposition: attachment;");
      pcVar15 = "smime.p7m";
      BIO_printf(bio," filename=\"%s\"%s",&DAT_0017668c,pcVar17);
      BIO_printf(bio,"Content-Type: %smime;",pcVar11);
    }
    BIO_printf(bio," name=\"%s\"%s",pcVar15,pcVar17);
    BIO_printf(bio,"Content-Transfer-Encoding: base64%s%s",pcVar17,pcVar17);
    iVar14 = B64_write_ASN1(bio,val,data,flags,it);
    if (iVar14 != 0) {
      BIO_printf(bio,"%s",pcVar17);
      iVar14 = 1;
      goto LAB_001113d6;
    }
  }
  else {
    RAND_pseudo_bytes(local_50,0x20);
    pbVar12 = local_50;
    do {
      bVar9 = *pbVar12 & 0xf;
      bVar10 = bVar9 + 0x30;
      if (9 < bVar9) {
        bVar10 = bVar9 + 0x37;
      }
      pbVar13 = pbVar12 + 1;
      *pbVar12 = bVar10;
      pbVar12 = pbVar13;
    } while (pbVar13 != local_30);
    bVar1 = false;
    local_30[0] = 0;
    BIO_printf(bio,"MIME-Version: 1.0%s",pcVar17);
    bVar2 = false;
    BIO_printf(bio,"Content-Type: multipart/signed;");
    BIO_printf(bio," protocol=\"%ssignature\";",pcVar11);
    BIO_puts(bio," micalg=\"");
    for (iVar14 = 0; iVar7 = sk_num(&mdalgs->stack), iVar14 < iVar7; iVar14 = iVar14 + 1) {
      if (bVar1) {
        BIO_write(bio,",",1);
      }
      ppAVar3 = (ASN1_OBJECT **)sk_value(&mdalgs->stack,iVar14);
      iVar7 = OBJ_obj2nid(*ppAVar3);
      pcVar4 = OBJ_nid2sn(iVar7);
      pEVar5 = EVP_get_digestbyname(pcVar4);
      if ((pEVar5 == (EVP_MD *)0x0) || (pEVar5->md_ctrl == (_func_1085 *)0x0)) {
LAB_001113ee:
        if (iVar7 == 0x2a0) {
          bVar1 = true;
          BIO_puts(bio,"sha-256");
        }
        else if (iVar7 < 0x2a1) {
          if (iVar7 == 4) {
            bVar1 = true;
            BIO_puts(bio,"md5");
          }
          else {
            if (iVar7 != 0x40) goto LAB_0011152e;
            bVar1 = true;
            BIO_puts(bio,"sha1");
          }
        }
        else if (iVar7 == 0x2a2) {
          bVar1 = true;
          BIO_puts(bio,"sha-512");
        }
        else if (iVar7 < 0x2a2) {
          bVar1 = true;
          BIO_puts(bio,"sha-384");
        }
        else {
          if (iVar7 == 0x329) {
            BIO_puts(bio,"gostr3411-94");
            break;
          }
LAB_0011152e:
          bVar1 = false;
          if (!bVar2) {
            bVar1 = true;
            BIO_puts(bio,"unknown");
            bVar2 = bVar1;
          }
        }
      }
      else {
        iVar6 = (*pEVar5->md_ctrl)((EVP_MD_CTX *)0x0,2,0,&local_5c);
        if (iVar6 < 1) {
          if (iVar6 == -2) goto LAB_001113ee;
          break;
        }
        BIO_puts(bio,(char *)local_5c);
        CRYPTO_free(local_5c);
        bVar1 = true;
      }
    }
    BIO_printf(bio,"\"; boundary=\"----%s\"%s%s",local_50,pcVar17,pcVar17);
    BIO_printf(bio,"This is an S/MIME signed message%s%s",pcVar17,pcVar17);
    BIO_printf(bio,"------%s%s",local_50,pcVar17);
    pvVar16 = it->funcs;
    local_60 = val;
    if ((flags & 0x8040U) != 0x40) {
      SMIME_crlf_copy(data,bio,flags);
LAB_001115ea:
      BIO_printf(bio,"%s------%s%s",pcVar17,local_50,pcVar17);
      BIO_printf(bio,"Content-Type: %ssignature;",pcVar11);
      BIO_printf(bio," name=\"smime.p7s\"%s",pcVar17);
      BIO_printf(bio,"Content-Transfer-Encoding: base64%s",pcVar17);
      BIO_printf(bio,"Content-Disposition: attachment;");
      BIO_printf(bio," filename=\"smime.p7s\"%s%s",pcVar17,pcVar17);
      B64_write_ASN1(bio,val,0,0,it);
      BIO_printf(bio,"%s------%s--%s%s",pcVar17,local_50,pcVar17,pcVar17);
      iVar14 = 1;
      goto LAB_001113d6;
    }
    if ((pvVar16 == (void *)0x0) || (*(code **)((int)pvVar16 + 0x10) == (code *)0x0)) {
      ERR_put_error(0xd,0xd6,0xca,"asn_mime.c",0x18a);
    }
    else {
      local_58 = (BIO *)0x0;
      local_54 = 0;
      local_5c = bio;
      iVar14 = (**(code **)((int)pvVar16 + 0x10))(0xc,&local_60,it,&local_5c);
      if (0 < iVar14) {
        SMIME_crlf_copy(data,local_58,flags);
        iVar14 = (**(code **)((int)pvVar16 + 0x10))(0xd,&local_60,it,&local_5c);
        while (bio != local_58) {
          pBVar8 = BIO_pop(local_58);
          BIO_free(local_58);
          local_58 = pBVar8;
        }
        if (0 < iVar14) goto LAB_001115ea;
      }
    }
  }
  iVar14 = 0;
LAB_001113d6:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar14;
}

