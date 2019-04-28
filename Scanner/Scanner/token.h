#ifndef SCANNER_TOKEN_H
#define SCANNER_TOKEN_H
enum TokenType{
    t_aeger,
    t_asignador,
    t_atomico,
    t_auctum,
    t_autem,
    t_casus,
    t_claudeo,
    t_coniugo,
    t_commutabilis,
    t_corpus,
    t_detrimentum,
    t_directus,
    t_dito,
    t_dixi,
    t_dotdot,
    t_efficio,
    t_end_ins,
    t_est,
    t_exemplar,
    t_finis,
    t_firmamentum,
    t_furibundus,
    t_gradus,
    t_ID,
    t_ign,
    t_impono,
    t_in,
    t_initum,
    t_itero,
    t_lit_bool,
    t_literalCaracter,
    t_literalEntero,
    t_literalFecha,
    t_literalString,
    t_mas_elem,
    t_modo_lectura,
    t_neco,
    t_nomen,
    t_non,
    t_op_arch_bin,
    t_op_arch_unario,
    t_op_binaria_l1,
    t_op_binaria_l1f,
    t_op_binaria_l2,
    t_op_binaria_l2f,
    t_op_binaria_logico,
    t_op_char,
    t_op_char_bool,
    t_op_comp,
    t_op_str_bin,
    t_op_str_ter_1,
    t_op_str_ter_2,
    t_op_str_un,
    t_op_unaria,
    t_op_unariaf,
    t_opus,
    t_ordo,
    t_panis,
    t_patentibus,
    t_PD,
    t_PD_arr,
    t_PD_dim,
    t_PD_reg,
    t_pergo,
    t_perpetus,
    t_PI,
    t_PI_arr,
    t_PI_dim,
    t_PI_reg,
    t_quantus,
    t_reditus,
    t_reg_acc,
    t_sigla,
    t_str_acc,
    t_sum,
    t_tempus,
    t_then_else,
    t_usque,
    t_asignador_str,
    t_pipe,
    t_salire,
    t_novis,
    t_EOF,
    t_error
};

struct Token{
    TokenType   type;
    char        *lexeme;
    int         attrib;
    int         line,
                column;

    Token(TokenType type, int line, int column):
        type(type), line(line), column(column){
    }

    Token(){}

    Token(TokenType type)
        :type(type){}

    Token(TokenType type, int attrib)
            :type(type), attrib(attrib){}
};
#endif //SCANNER_TOKEN_H
