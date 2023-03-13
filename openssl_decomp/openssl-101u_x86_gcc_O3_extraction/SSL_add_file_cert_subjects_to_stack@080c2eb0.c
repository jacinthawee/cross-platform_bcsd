
int SSL_add_file_cert_subjects_to_stack(stack_st_X509_NAME *stackCAs,char *file)

{
  void *pvVar1;
  BIO_METHOD *type;
  BIO *bp;
  long lVar2;
  X509 *pXVar3;
  X509_NAME *pXVar4;
  int iVar5;
  int in_GS_OFFSET;
  X509 *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = (X509 *)0x0;
  pvVar1 = (void *)sk_set_cmp_func(stackCAs,xname_cmp);
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    iVar5 = 0;
    ERR_put_error(0x14,0xd8,0x41,"ssl_cert.c",0x2c2);
  }
  else {
    lVar2 = BIO_ctrl(bp,0x6c,3,file);
    if (lVar2 == 0) {
LAB_080c2f0e:
      iVar5 = 0;
    }
    else {
      while( true ) {
        pXVar3 = PEM_read_bio_X509(bp,&local_24,(undefined1 *)0x0,(void *)0x0);
        if (pXVar3 == (X509 *)0x0) break;
        pXVar4 = X509_get_subject_name(local_24);
        if (pXVar4 == (X509_NAME *)0x0) goto LAB_080c2f0e;
        pXVar4 = X509_NAME_dup(pXVar4);
        if (pXVar4 == (X509_NAME *)0x0) goto LAB_080c2f0e;
        iVar5 = sk_find(&stackCAs->stack,pXVar4);
        if (iVar5 < 0) {
          sk_push(&stackCAs->stack,pXVar4);
        }
        else {
          X509_NAME_free(pXVar4);
        }
      }
      ERR_clear_error();
      iVar5 = 1;
    }
    BIO_free(bp);
  }
  if (local_24 != (X509 *)0x0) {
    X509_free(local_24);
  }
  sk_set_cmp_func(stackCAs,pvVar1);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

