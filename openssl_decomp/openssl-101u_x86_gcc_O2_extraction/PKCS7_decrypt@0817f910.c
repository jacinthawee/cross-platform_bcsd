
int PKCS7_decrypt(PKCS7 *p7,EVP_PKEY *pkey,X509 *cert,BIO *data,int flags)

{
  int iVar1;
  uint uVar2;
  BIO *b;
  int iVar3;
  BIO_METHOD *type;
  BIO *b_00;
  BIO *in;
  long lVar4;
  int in_GS_OFFSET;
  undefined local_1020 [4096];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (p7 == (PKCS7 *)0x0) {
    iVar3 = 0x20d;
    iVar1 = 0x8f;
  }
  else {
    iVar1 = OBJ_obj2nid(p7->type);
    if (iVar1 == 0x17) {
      if ((cert != (X509 *)0x0) && (uVar2 = X509_check_private_key(cert,pkey), uVar2 == 0)) {
        ERR_put_error(0x21,0x72,0x7f,"pk7_smime.c",0x218);
        goto LAB_0817fa2d;
      }
      b = PKCS7_dataDecode(p7,pkey,(BIO *)0x0,cert);
      if (b != (BIO *)0x0) {
        if ((flags & 1U) == 0) {
          do {
            iVar1 = BIO_read(b,local_1020,0x1000);
            if (iVar1 < 1) {
              uVar2 = 1;
              iVar1 = BIO_method_type(b);
              if (iVar1 == 0x20a) {
                lVar4 = BIO_ctrl(b,0x71,0,(void *)0x0);
                uVar2 = (uint)(lVar4 != 0);
              }
              goto LAB_0817f9fa;
            }
            iVar3 = BIO_write(data,local_1020,iVar1);
          } while (iVar1 == iVar3);
          uVar2 = 0;
LAB_0817f9fa:
          BIO_free_all(b);
        }
        else {
          type = BIO_f_buffer();
          b_00 = BIO_new(type);
          if (b_00 == (BIO *)0x0) {
            ERR_put_error(0x21,0x72,0x41,"pk7_smime.c",0x225);
            BIO_free_all(b);
            uVar2 = 0;
          }
          else {
            in = BIO_push(b_00,b);
            if (in == (BIO *)0x0) {
              ERR_put_error(0x21,0x72,0x41,"pk7_smime.c",0x22a);
              BIO_free_all(b_00);
              BIO_free_all(b);
              uVar2 = 0;
            }
            else {
              uVar2 = SMIME_text(in,data);
              if (((0 < (int)uVar2) && (iVar1 = BIO_method_type(b), iVar1 == 0x20a)) &&
                 (lVar4 = BIO_ctrl(b,0x71,0,(void *)0x0), lVar4 == 0)) {
                uVar2 = 0;
              }
              BIO_free_all(in);
            }
          }
        }
        goto LAB_0817fa2d;
      }
      iVar3 = 0x21d;
      iVar1 = 0x77;
    }
    else {
      iVar3 = 0x212;
      iVar1 = 0x71;
    }
  }
  ERR_put_error(0x21,0x72,iVar1,"pk7_smime.c",iVar3);
  uVar2 = 0;
LAB_0817fa2d:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

