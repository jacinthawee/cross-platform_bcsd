
void X509V3_section_free(X509V3_CTX *ctx,stack_st_CONF_VALUE *section)

{
  _func_4247 *UNRECOVERED_JUMPTABLE;
  
  if ((section != (stack_st_CONF_VALUE *)0x0) &&
     (UNRECOVERED_JUMPTABLE = ctx->db_meth->free_section, UNRECOVERED_JUMPTABLE != (_func_4247 *)0x0
     )) {
                    /* WARNING: Could not recover jumptable at 0x0816a1bd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(ctx->db,section);
    return;
  }
  return;
}

