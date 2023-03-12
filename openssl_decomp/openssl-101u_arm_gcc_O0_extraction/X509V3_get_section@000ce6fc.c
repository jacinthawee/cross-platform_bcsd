
stack_st_CONF_VALUE * X509V3_get_section(X509V3_CTX *ctx,char *section)

{
  stack_st_CONF_VALUE *psVar1;
  _func_4245 *UNRECOVERED_JUMPTABLE;
  
  if (((ctx->db != (void *)0x0) && (ctx->db_meth != (X509V3_CONF_METHOD *)0x0)) &&
     (UNRECOVERED_JUMPTABLE = ctx->db_meth->get_section, UNRECOVERED_JUMPTABLE != (_func_4245 *)0x0)
     ) {
                    /* WARNING: Could not recover jumptable at 0x000ce714. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    psVar1 = (*UNRECOVERED_JUMPTABLE)(ctx->db,section);
    return psVar1;
  }
  ERR_put_error(0x22,0x8e,0x94,"v3_conf.c",0x196);
  return (stack_st_CONF_VALUE *)0x0;
}

