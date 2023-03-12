
TXT_DB * load_index(char *param_1,int *param_2)

{
  byte bVar1;
  BIO_METHOD *type;
  BIO *bp;
  long lVar2;
  TXT_DB *db;
  CONF *conf;
  int iVar3;
  TXT_DB *pTVar4;
  byte *pbVar5;
  CONF *conf_00;
  int local_11c;
  char acStack_118 [256];
  
  type = BIO_s_file();
  bp = BIO_new(type);
  local_11c = -1;
  if (bp == (BIO *)0x0) {
    ERR_print_errors(bio_err);
    return (TXT_DB *)0x0;
  }
  lVar2 = BIO_ctrl(bp,0x6c,3,param_1);
  if (lVar2 < 1) {
    perror(param_1);
    BIO_printf(bio_err,"unable to open \'%s\'\n",param_1);
    pTVar4 = (TXT_DB *)0x0;
  }
  else {
    db = TXT_DB_read(bp,6);
    pTVar4 = db;
    if (db != (TXT_DB *)0x0) {
      BIO_snprintf(acStack_118,0x100,"%s.attr",param_1);
      conf = NCONF_new((CONF_METHOD *)0x0);
      iVar3 = NCONF_load(conf,acStack_118,&local_11c);
      conf_00 = conf;
      if (iVar3 < 1) {
        if (local_11c < 1) {
          conf_00 = (CONF *)0x0;
          NCONF_free(conf);
          goto LAB_00034546;
        }
        BIO_printf(bio_err,"error on line %ld of db attribute file \'%s\'\n",local_11c,acStack_118);
      }
      else {
LAB_00034546:
        pTVar4 = (TXT_DB *)CRYPTO_malloc(8,"apps.c",0x6f0);
        if (pTVar4 != (TXT_DB *)0x0) {
          pTVar4->data = (stack_st_OPENSSL_PSTRING *)db;
          if (param_2 == (int *)0x0) {
            pTVar4->num_fields = 1;
          }
          else {
            pTVar4->num_fields = *param_2;
          }
          if (conf_00 == (CONF *)0x0) goto joined_r0x00034640;
          pbVar5 = (byte *)NCONF_get_string(conf_00,(char *)0x0,"unique_subject");
          if (pbVar5 != (byte *)0x0) {
            bVar1 = *pbVar5;
            if (bVar1 == 0x4e) {
LAB_000345ce:
              iVar3 = 0;
            }
            else {
              if (bVar1 < 0x4f) {
                if ((bVar1 == 0x30) || (bVar1 == 0x46)) goto LAB_000345ce;
              }
              else if ((bVar1 == 0x66) || (bVar1 == 0x6e)) goto LAB_000345ce;
              iVar3 = 1;
            }
            pTVar4->num_fields = iVar3;
          }
          NCONF_free(conf_00);
          goto LAB_0003459a;
        }
        fwrite("Out of memory\n",1,0xe,stderr);
        conf = conf_00;
      }
      if (conf != (CONF *)0x0) {
        NCONF_free(conf);
      }
      pTVar4 = (TXT_DB *)0x0;
      TXT_DB_free(db);
      goto LAB_0003459a;
    }
  }
joined_r0x00034640:
  if (bp == (BIO *)0x0) {
    return pTVar4;
  }
LAB_0003459a:
  BIO_free_all(bp);
  return pTVar4;
}

