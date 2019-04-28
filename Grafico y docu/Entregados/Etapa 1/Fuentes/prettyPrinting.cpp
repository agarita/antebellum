//
// Created by luisg on 31/3/2019.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include "prettyPrinting.h"

using namespace std;

std::map<TokenType, string> color ={
        {t_aeger, "00FFFF"},
        {t_asignador, "DC143C"},
        {t_atomico, "98FB98"},
        {t_auctum, "FFD700"},
        {t_autem, "E6E6FA"},
        {t_casus, "FF1493"},
        {t_claudeo, "00FFFF"},
        {t_coniugo, "0000FF"},
        {t_commutabilis, "006400"},
        {t_corpus, "9370DB"},
        {t_detrimentum, "9932CC"},
        {t_directus, "4169E1"},
        {t_dito, "800080"},
        {t_dixi, "48D1CC"},
        {t_dotdot, "FDF5E6"},
        {t_efficio, "7CFC00"},
        {t_end_ins, "00FF00"},
        {t_est, "A9A9A9"},
        {t_exemplar, "90EE90"},
        {t_finis, "FFE4B5"},
        {t_firmamentum, "000000"},
        {t_furibundus, "40E0D0"},
        {t_gradus, "DB7093"},
        {t_ID, "008000"},
        {t_ign, "FF00FF"},
        {t_impono, "FFFAF0"},
        {t_in, "00FA9A"},
        {t_initum, "FFFF00"},
        {t_itero, "E9967A"},
        {t_lit_bool, "8B008B"},
        {t_literalCaracter, "6A5ACD"},
        {t_literalEntero, "7FFF00"},
        {t_literalFecha, "FFDAB9"},
        {t_literalString, "D2691E"},
        {t_mas_elem, "DCDCDC"},
        {t_modo_lectura, "87CEFA"},
        {t_neco, "F0FFF0"},
        {t_nomen, "FFACD"},
        {t_non, "00CED1"},
        {t_op_arch_bin, "4B0082"},
        {t_op_arch_unario, "F5FFFA"},
        {t_op_binaria_l1, "FF7F50"},
        {t_op_binaria_l1f, "808080"},
        {t_op_binaria_l2, "2F4F4F"},
        {t_op_binaria_l2f, "CD5C5C"},
        {t_op_binaria_logico, "808000"},
        {t_op_char, "20B2AA"},
        {t_op_char_bool, "4682B4"},
        {t_op_comp, "6495ED"},
        {t_op_str_bin, "5F9EA0"},
        {t_op_str_ter_1, "000080"},
        {t_op_str_ter_2, "FF6347"},
        {t_op_str_un, "FFE4E1"},
        {t_op_unaria, "00FF7F"},
        {t_op_unariaf, "696969"},
        {t_opus, "228B22"},
        {t_ordo, "DEB887"},
        {t_panis, "D3D3D3"},
        {t_patentibus, "32CD32"},
        {t_PD, "008080"},
        {t_PD_arr, "66CDAA"},
        {t_PD_dim, "FFFFE0"},
        {t_PD_reg, "0000CD"},
        {t_pergo, "BDB76B"},
        {t_perpetus, "FFA500"},
        {t_PI, "DDA0DD"},
        {t_PI_arr, "F0E68C"},
        {t_PI_dim, "B0C4DE"},
        {t_PI_reg, "BA55D3"},
        {t_quantus, "7B68EE"},
        {t_reditus, "D2B48C"},
        {t_reg_acc, "7FFFD4"},
        {t_sigla, "3CB371"},
        {t_str_acc, "1E90FF"},
        {t_sum, "8B0000"},
        {t_tempus, "FFA07A"},
        {t_then_else, "ADFF2F"},
        {t_usque, "F5F5F5"},
        {t_asignador_str, "F0F0F0"},
        {t_pipe, "F8F8F8"},
        {t_EOF, "000000"},
        {t_error, "FF0000"}
};

void crearHTML(scanner mysca) {
    ofstream html;
    html.open(".//report.html");
    html << "<!DOCTYPE html><html><head></head><body bgcolor='#000000'>"; //starting html

    int count = mysca.resqueue.size();
    cout << count << endl;
    for (int i = 0; i < count; i++){
        Token tok = mysca.getToken();
        string clr = color[tok.type];
        cout << "Cambio color:"<< clr <<endl;
        html << "<span style='color:#" << clr << "' style='font-weight: bold'>" << tok.lexeme << " </span>";
    }
    //ending html
    html << "</body></html>";
    html.close();

    cout << "hizo archivo" << endl;
};

