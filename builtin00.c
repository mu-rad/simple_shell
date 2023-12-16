#include "shell.h"

/**
 * _myexit - this exits the shell
 * @info: the structure storing potential arguments, Used to maintain
 *      constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
        int checkexit;

        if (info->argv[1])  /* checks If there is an exit arguement */
        {
                checkexit = _erratoi(info->argv[1]);
                if (checkexit == -1)
                {
                        info->status = 2;
                        print_error(info, "Sorry illegal number: ");
                        _eputs(info->argv[1]);
                        _eputchar('\n');
                        return (1);
                }
                info->err_num = _erratoi(info->argv[1]);
                return (-2);
        }
        info->err_num = -1;
        return (-2);
}

/**
 * _mycd - this changes the current directory of the process
 * @info: Structure storing potential arguments used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _mycd(info_t *info)
{
        char *s, *dir, buffer[1024];
        int chdirret;

        s = getcwd(buffer, 1024);
        if (!s)
                _puts("TODO: >>getcwd failure emsg here<<\n");
        if (!info->argv[1])
        {
                dir = _getenv(info, "HOME=");
                if (!dir)
                        chdirret = /* TODO: what should this be? */
                                chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
                else
                        chdirret = chdir(dir);
        }
        else if (_strcmp(info->argv[1], "-") == 0)
        {
                if (!_getenv(info, "OLDPWD="))
                {
                        _puts(s);
                        _putchar('\n');
                        return (1);
                }
                _puts(_getenv(info, "OLDPWD=")), _putchar('\n');
                chdirret = /* TODO: what should this be? */
                        chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
        }
        else
                chdirret = chdir(info->argv[1]);
        if (chdirret == -1)
        {
                print_error(info, "can't cd to ");
                _eputs(info->argv[1]), _eputchar('\n');
        }
        else
        {
                _setenv(info, "OLDPWD", _getenv(info, "PWD="));
                _setenv(info, "PWD", getcwd(buffer, 1024));
        }
        return (0);
}
/**
 * _myhelp - responsible for changing the current directory of the process
 * @info: Structure holding potential arguments used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
        char **arg_array;

        arg_array = info->argv;
        _puts("help call works, function not implemented yet \n");
        if (0)
                _puts(*arg_array); /* temp att_unused workaround */
        return (0);
}

