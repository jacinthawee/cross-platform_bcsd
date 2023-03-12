
ASN1_VALUE * SMIME_read_ASN1(BIO *bio,BIO **bcont,ASN1_ITEM *it)

{
  _STACK *st;
  int iVar1;
  void *pvVar2;
  BIO_METHOD *pBVar3;
  BIO *pBVar4;
  BIO *pBVar5;
  ASN1_VALUE *pAVar6;
  BIO *in;
  char *pcVar7;
  _STACK *local_38;
  char *local_34 [4];
  
  local_38 = (_STACK *)0x0;
  if (bcont != (BIO **)0x0) {
    *bcont = (BIO *)0x0;
  }
  st = (_STACK *)mime_parse_hdr(bio);
  if (st == (_STACK *)0x0) {
    ERR_put_error(0xd,0xd4,0xcf,"asn_mime.c",0x1bd);
  }
  else {
    local_34[0] = "content-type";
    iVar1 = sk_find(st,local_34);
    if (((iVar1 < 0) || (pvVar2 = sk_value(st,iVar1), pvVar2 == (void *)0x0)) ||
       (pcVar7 = *(char **)((int)pvVar2 + 4), pcVar7 == (char *)0x0)) {
      sk_pop_free(st,mime_hdr_free + 1);
      ERR_put_error(0xd,0xd4,0xd1,"asn_mime.c",0x1c3);
      st = (_STACK *)0x0;
    }
    else {
      iVar1 = strcmp(pcVar7,"multipart/signed");
      if (iVar1 == 0) {
        local_34[0] = "boundary";
        iVar1 = sk_find(*(_STACK **)((int)pvVar2 + 8),local_34);
        if (((iVar1 < 0) ||
            (pvVar2 = sk_value(*(_STACK **)((int)pvVar2 + 8),iVar1), pvVar2 == (void *)0x0)) ||
           (*(int *)((int)pvVar2 + 4) == 0)) {
          sk_pop_free(st,mime_hdr_free + 1);
          ERR_put_error(0xd,0xd4,0xd3,"asn_mime.c",0x1ce);
          st = (_STACK *)0x0;
        }
        else {
          iVar1 = multi_split(bio,*(int *)((int)pvVar2 + 4),&local_38);
          sk_pop_free(st,mime_hdr_free + 1);
          if ((iVar1 == 0) || (iVar1 = sk_num(local_38), iVar1 != 2)) {
            ERR_put_error(0xd,0xd4,0xd2,"asn_mime.c",0x1d4);
LAB_00110dac:
            sk_pop_free(local_38,BIO_vfree + 1);
            return (ASN1_VALUE *)0x0;
          }
          pBVar4 = (BIO *)sk_value(local_38,1);
          st = (_STACK *)mime_parse_hdr();
          if (st == (_STACK *)0x0) {
            ERR_put_error(0xd,0xd4,0xd0,"asn_mime.c",0x1dd);
            sk_pop_free(local_38,BIO_vfree + 1);
          }
          else {
            local_34[0] = "content-type";
            iVar1 = sk_find(st,local_34);
            if (((-1 < iVar1) && (pvVar2 = sk_value(st,iVar1), pvVar2 != (void *)0x0)) &&
               (pcVar7 = *(char **)((int)pvVar2 + 4), pcVar7 != (char *)0x0)) {
              iVar1 = strcmp(pcVar7,"application/x-pkcs7-signature");
              if ((iVar1 == 0) || (iVar1 = strcmp(pcVar7,"application/pkcs7-signature"), iVar1 == 0)
                 ) {
                sk_pop_free(st,mime_hdr_free + 1);
                pBVar3 = BIO_f_base64();
                pBVar5 = BIO_new(pBVar3);
                if (pBVar5 == (BIO *)0x0) {
                  ERR_put_error(0xd,0xd1,0x41,"asn_mime.c",0xbb);
                }
                else {
                  in = BIO_push(pBVar5,pBVar4);
                  pAVar6 = (ASN1_VALUE *)ASN1_item_d2i_bio(it,in,(void *)0x0);
                  if (pAVar6 != (ASN1_VALUE *)0x0) {
                    BIO_ctrl(in,0xb,0,(void *)0x0);
                    BIO_pop(in);
                    BIO_free(pBVar5);
                    if (bcont == (BIO **)0x0) {
                      sk_pop_free(local_38,BIO_vfree + 1);
                      return pAVar6;
                    }
                    pBVar5 = (BIO *)sk_value(local_38,0);
                    *bcont = pBVar5;
                    BIO_free(pBVar4);
                    sk_free(local_38);
                    return pAVar6;
                  }
                  ERR_put_error(0xd,0xd1,0x6e,"asn_mime.c",0xc1);
                  BIO_ctrl(in,0xb,0,(void *)0x0);
                  BIO_pop(in);
                  BIO_free(pBVar5);
                }
                ERR_put_error(0xd,0xd4,0xcc,"asn_mime.c",0x1f6);
              }
              else {
                ERR_put_error(0xd,0xd4,0xd5,"asn_mime.c",0x1ed);
                ERR_add_error_data(2,"type: ",*(undefined4 *)((int)pvVar2 + 4));
                sk_pop_free(st,mime_hdr_free + 1);
              }
              goto LAB_00110dac;
            }
            sk_pop_free(st,mime_hdr_free + 1);
            ERR_put_error(0xd,0xd4,0xd4,"asn_mime.c",0x1e7);
            st = (_STACK *)0x0;
          }
        }
      }
      else {
        iVar1 = strcmp(pcVar7,"application/x-pkcs7-mime");
        if ((iVar1 == 0) || (iVar1 = strcmp(pcVar7,"application/pkcs7-mime"), iVar1 == 0)) {
          sk_pop_free(st,mime_hdr_free + 1);
          pBVar3 = BIO_f_base64();
          pBVar4 = BIO_new(pBVar3);
          if (pBVar4 == (BIO *)0x0) {
            ERR_put_error(0xd,0xd1,0x41,"asn_mime.c",0xbb);
          }
          else {
            pBVar5 = BIO_push(pBVar4,bio);
            pAVar6 = (ASN1_VALUE *)ASN1_item_d2i_bio(it,pBVar5,(void *)0x0);
            if (pAVar6 != (ASN1_VALUE *)0x0) {
              BIO_ctrl(pBVar5,0xb,0,(void *)0x0);
              BIO_pop(pBVar5);
              BIO_free(pBVar4);
              return pAVar6;
            }
            ERR_put_error(0xd,0xd1,0x6e,"asn_mime.c",0xc1);
            BIO_ctrl(pBVar5,0xb,0,(void *)0x0);
            BIO_pop(pBVar5);
            BIO_free(pBVar4);
          }
          ERR_put_error(0xd,0xd4,0xcb,"asn_mime.c",0x210);
          st = (_STACK *)0x0;
        }
        else {
          ERR_put_error(0xd,0xd4,0xcd,"asn_mime.c",0x207);
          ERR_add_error_data(2,"type: ",*(undefined4 *)((int)pvVar2 + 4));
          sk_pop_free(st,mime_hdr_free + 1);
          st = (_STACK *)0x0;
        }
      }
    }
  }
  return (ASN1_VALUE *)st;
}

