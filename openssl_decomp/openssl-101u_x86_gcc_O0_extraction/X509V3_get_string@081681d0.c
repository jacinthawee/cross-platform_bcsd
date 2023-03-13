
char * X509V3_get_string(X509V3_CTX *ctx,char *name,char *section)

{
  _func_4244 *UNRECOVERED_JUMPTABLE;
  char *pcVar1;
  
  if (((ctx->db != (void *)0x0) && (ctx->db_meth != (X509V3_CONF_METHOD *)0x0)) &&
     (UNRECOVERED_JUMPTABLE = ctx->db_meth->get_string, UNRECOVERED_JUMPTABLE != (_func_4244 *)0x0))
  {
                    /* WARNING: Could not recover jumptable at 0x081681f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar1 = (*UNRECOVERED_JUMPTABLE)(ctx->db,name,section);
    return pcVar1;
  }
  ERR_put_error(0x22,0x8f,0x94,"v3_conf.c",0x18a);
  return (char *)0x0;
}

