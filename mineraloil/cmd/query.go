package cmd

import (
	"encoding/json"
	"fmt"
	"os"
	"path"

	"github.com/spf13/cobra"
)

const BERVENV = "./__bervenv__"

var SYSPACKS = path.Join(BERVENV, "syspacks")

// queryCmd represents the query command
var queryCmd = &cobra.Command{
	Use:   "query",
	Short: "Queries a package/packages",
	Args:  cobra.MinimumNArgs(1),
	RunE: func(cmd *cobra.Command, args []string) error {
		fmt.Println("Query called")
		for _, pack := range args {
			jsonPath := path.Join(SYSPACKS, pack, "pkg.json")
			m := map[string]any{}
			buffer, err := os.ReadFile(jsonPath)
			if err != nil {
				return err
			}
			json.Unmarshal(buffer, &m)
		}
		return nil
	},
}

func init() {
	rootCmd.AddCommand(queryCmd)

	// Here you will define your flags and configuration settings.

	// Cobra supports Persistent Flags which will work for this command
	// and all subcommands, e.g.:
	// queryCmd.PersistentFlags().String("foo", "", "A help for foo")

	// Cobra supports local flags which will only run when this command
	// is called directly, e.g.:
	// queryCmd.Flags().BoolP("toggle", "t", false, "Help message for toggle")
}
