
X509 * load_cert(BIO *param_1,X509 **param_2,int param_3,undefined4 param_4,undefined4 param_5,
                code *param_6)

{
  ASN1_OCTET_STRING *pAVar1;
  BIO_METHOD *type;
  BIO *bp;
  long lVar2;
  NETSCAPE_X509 *a;
  int iVar3;
  uchar *puVar4;
  uchar *puVar5;
  int in_GS_OFFSET;
  bool bVar6;
  byte bVar7;
  code *pcVar8;
  X509 **ppXVar9;
  X509 *local_24;
  int local_20;
  
  bVar7 = 0;
  local_24 = (X509 *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_print_errors(param_1);
    if (local_24 == (X509 *)0x0) {
      BIO_printf(param_1,"unable to load certificate\n");
      ERR_print_errors(param_1);
    }
    goto LAB_0807a452;
  }
  if (param_2 == (X509 **)0x0) {
    ppXVar9 = (X509 **)0x0;
    pcVar8 = (code *)0x2;
    setvbuf(stdin,(char *)0x0,2,0);
    BIO_ctrl(bp,0x6a,0,stdin);
    if (param_3 != 1) goto LAB_0807a40b;
LAB_0807a4f0:
    local_24 = d2i_X509_bio(bp,(X509 **)0x0);
    param_6 = pcVar8;
  }
  else {
    pcVar8 = (code *)0x3;
    ppXVar9 = param_2;
    lVar2 = BIO_ctrl(bp,0x6c,3,param_2);
    if (lVar2 < 1) {
      BIO_printf(param_1,"Error opening %s %s\n",param_6,param_2);
      ERR_print_errors(param_1);
      ppXVar9 = param_2;
    }
    else {
      if (param_3 == 1) goto LAB_0807a4f0;
LAB_0807a40b:
      if (param_3 == 4) {
        param_6 = (code *)0x0;
        a = (NETSCAPE_X509 *)ASN1_item_d2i_bio((ASN1_ITEM *)NETSCAPE_X509_it,bp,(void *)0x0);
        if (a != (NETSCAPE_X509 *)0x0) {
          pAVar1 = a->header;
          iVar3 = 0xc;
          if (pAVar1->length < 0xd) {
            iVar3 = pAVar1->length;
          }
          bVar6 = true;
          puVar4 = "certificate";
          puVar5 = pAVar1->data;
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar6 = *puVar4 == *puVar5;
            puVar4 = puVar4 + (uint)bVar7 * -2 + 1;
            puVar5 = puVar5 + (uint)bVar7 * -2 + 1;
          } while (bVar6);
          if (bVar6) {
            local_24 = a->cert;
            a->cert = (X509 *)0x0;
            NETSCAPE_X509_free(a);
          }
          else {
            NETSCAPE_X509_free(a);
            BIO_printf(param_1,"Error reading header on certificate\n");
          }
        }
      }
      else if (param_3 == 3) {
        ppXVar9 = (X509 **)0x0;
        param_6 = password_callback;
        local_24 = PEM_read_bio_X509_AUX(bp,(X509 **)0x0,password_callback,(void *)0x0);
      }
      else if (param_3 == 5) {
        ppXVar9 = &local_24;
        param_6 = (code *)0x0;
        load_pkcs12_constprop_4(0,0,0,ppXVar9);
      }
      else {
        BIO_printf(param_1,"bad input format specified for %s\n",param_6);
      }
    }
  }
  if (local_24 == (X509 *)0x0) {
    BIO_printf(param_1,"unable to load certificate\n",param_6,ppXVar9);
    ERR_print_errors(param_1);
  }
  BIO_free(bp);
LAB_0807a452:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_24;
}

